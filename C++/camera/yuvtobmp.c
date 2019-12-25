/*
 * YUYV转换成bmp模块
 */

#include <yuvtobmp.h>
#include <mytypes.h>
#include <errmsg.h>

#include <pthread.h>

#include "jpeglib.h"

/*
 * YUV4：2：2转RGB
 * y0 cb0 y1 cr0 ---> r0 g0 b0 r1 g1 b1 
 * r0 = YCbCrtoR(y0, cb0, cr0);
 * g0 = YCbCrtoG(y0, cb0, cr0);
 * b0 = YCbCrtoB(y0, cb0, cr0);
 * r1 = YCbCrtoR(y1, cb0, cr0);
 * g1 = YCbCrtoG(y1, cb0, cr0);
 * b1 = YCbCrtoB(y1, cb0, cr0);
 * YUYV转RGB公式
 */
#define YCbCrtoR(Y,Cb,Cr) (1000000*Y + 1370705*(Cr-128))/1000000
#define YCbCrtoG(Y,Cb,Cr) (1000000*Y - 337633*(Cb-128) - 698001*(Cr-128))/1000000
#define YCbCrtoB(Y,Cb,Cr) (1000000*Y + 1732446*(Cb-128))/1000000

/*rgb16缓存 len: w*h*2 */
typedef struct __rgb16data
{
	int w;		/*rgb16缓存长度w*h*2*/
	int h;		
	u8* buf;	/*rgb16缓存首地址*/
}RGB16;

/*rgb24缓存 len: w*h*3 */
typedef struct __rgb24data
{
	int w;		/*rgb16缓存长度w*h*3*/
	int h;		
	u8* buf;	/*rgb24缓存首地址*/
}RGB24;

/*BMP信息头*/
typedef struct tagBMPFILEHEADER
{
	u16 align;		
	u16 bfType;		// the flag of bmp, value is "BM"
	u32 bfSize;		// size BMP file ,unit is bytes
	u32 bfReserved;		// 0
	u32 bfOffBits;		// must be 54
}BMPFILEHEADER;

typedef struct tagBMPINFOHEADER
{
	u32 biSize;		// must be 0x28
	u32 biWidth;
	u32 biHeight;
	u16 biPlanes;		// must be 1
	u16 biBitCount;
	u32 biCompression;
	u32 biSizeImage;
	u32 biXPelsPerMeter;
	u32 biYPelsPerMeter;
	u32 biClrUsed;
	u32 biClrImportant;
}BMPINFOHEADER;

/*bmp缓存 len: bf+bi+rgb */
typedef struct __bmpdata
{
	int len;	/*54+rgb24.len*/
	u8* buf;	/*bmp缓存首地址*/
}BMP;

static RGB16 __rgb16;
static RGB24 __rgb24;
static BMP   __bmp24;

static pthread_mutex_t mutex;

/*初始化及分配空间*/
void init_conv(u32 w, u32 h)
{
	/*初始化*/
	__rgb16.w = w;
	__rgb16.h = h;
	__rgb24.w = w;
	__rgb24.h = h;
	__bmp24.len = (sizeof(BMPFILEHEADER)-2)+sizeof(BMPINFOHEADER)+w*h*3;


	int len = w*h*2;	
	__rgb16.buf = (u8 *)malloc(len);
	ASSERT(NULL != __rgb16.buf);

	len = w*h*3;
	__rgb24.buf = (u8 *)malloc(len);
	ASSERT(NULL != __rgb24.buf);
	
	__bmp24.buf = (u8 *)malloc(__bmp24.len);
	ASSERT(NULL != __bmp24.buf);

	pthread_mutex_init(&mutex, NULL);
}

/*分配空间*/
void uninit_conv()
{
	if(__rgb16.buf)
		free(__rgb16.buf);
		
	if(__rgb24.buf)
		free(__rgb24.buf);
		
	if(__bmp24.buf)
		free(__bmp24.buf);
	
	__rgb16.buf = NULL;
	__rgb24.buf = NULL;
	__bmp24.buf = NULL;
}

/*
 *功能：YUYV转RGB16函数
 */
void yuvtorgb16(u16**rgb16, u8 *yuv, u32 w, u32 h)
{
	u8 y0,cb0,y1,cr0;
	int r, g, b;
	
	ASSERT(w == __rgb16.w);
	ASSERT(h == __rgb16.h);

	for(int i = 0; i < h; i++){
		u16 *prgb = (u16*)__rgb16.buf;
		prgb += (w*(h-i-1));
		for(int j = 0 ; j < w; j+=2){
			y0  = *yuv++;
			cb0 = *yuv++;
			y1  = *yuv++;
			cr0 = *yuv++;
	
			r = YCbCrtoR(y0, cb0, cr0);
			g = YCbCrtoG(y0, cb0, cr0);
			b = YCbCrtoB(y0, cb0, cr0);	
			if (r > 255) r = 255;
			if (r < 0  ) r = 0;
			if (g > 255) g = 255;
			if (g < 0  ) g = 0;
			if (b > 255) b = 255;
			if (b < 0  ) b = 0;
			// 5:6:5 16bit format
			*prgb++ = (((u16)r>>3)<<11) | (((u16)g>>2)<<5) | (((u16)b>>3)<<0);
		
			r = YCbCrtoR(y1, cb0, cr0);
			g = YCbCrtoG(y1, cb0, cr0);
			b = YCbCrtoB(y1, cb0, cr0);
			if (r > 255) r = 255;
			if (r < 0  ) r = 0;
			if (g > 255) g = 255;
			if (g < 0  ) g = 0;
			if (b > 255) b = 255;
			if (b < 0  ) b = 0;
		
			// 5:6:5 16bit format
			*prgb++ = (((u16)r>>3)<<11) | (((u16)g>>2)<<5) | (((u16)b>>3)<<0);
		}
	}
	
	if(rgb16)
		*rgb16 = (u16*)__rgb16.buf;
}
/*RGB16转BMP*/
u32 getbmp16(u8 **bmpaddr, u8 *yuv, u32 w, u32 h)
{
	int len = w*h*2;

	/*yuv4:2:2 ---> rgb24*/
	yuvtorgb16(NULL, yuv, w, h);

	//文件头信息
	BMPFILEHEADER bmpf;
	bmpf.bfType = 0x4D42;
	bmpf.bfSize = sizeof(BMPFILEHEADER)-2 + sizeof(BMPINFOHEADER) + len;
	bmpf.bfReserved = 0;
	bmpf.bfOffBits  = sizeof(BMPFILEHEADER)-2 + sizeof(BMPINFOHEADER);

	//Bitmap头信息
	BMPINFOHEADER bmpi; 
	bmpi.biSize=sizeof(BMPINFOHEADER); 
	bmpi.biWidth=w; 
	bmpi.biHeight=h; 
	bmpi.biPlanes=1; 
	bmpi.biBitCount=16; 
	bmpi.biCompression=0; 
	bmpi.biSizeImage=len; 
	bmpi.biXPelsPerMeter=0; 
	bmpi.biYPelsPerMeter=0; 
	bmpi.biClrUsed=0; 
	bmpi.biClrImportant=0; 
        
        memcpy(__bmp24.buf, &bmpf.bfType, 14);
        memcpy(__bmp24.buf+14, &bmpi, 40);

	u8* prgb16 = __rgb16.buf;
	u8* pbmp   = __bmp24.buf+54;

	memcpy(pbmp, prgb16, sizeof(BMPFILEHEADER)-2 + sizeof(BMPINFOHEADER) + len);

        *bmpaddr = __bmp24.buf;
	return sizeof(BMPFILEHEADER)-2 + sizeof(BMPINFOHEADER) + len;
}

/*
 *功能：YUYV转RGB24函数

 */
void yuvtorgb24(u8**rgb24, u8 *yuv, u32 w, u32 h)
{
	u8 y0,cb0,y1,cr0;
	int r, g, b;
	
	ASSERT(w <= __rgb24.w);
	ASSERT(h <= __rgb24.h);

	for(int i = 0; i < h; i++){
		u8 *prgb = __rgb24.buf;
		prgb += (w*(h-i-1)*3);
		for(int j = 0 ; j < w; j+=2){
			y0  = *yuv++;
			cb0 = *yuv++;
			y1  = *yuv++;
			cr0 = *yuv++;
	
			r = YCbCrtoR(y0, cb0, cr0);
			g = YCbCrtoG(y0, cb0, cr0);
			b = YCbCrtoB(y0, cb0, cr0);	
			if (r > 255) r = 255;
			if (r < 0  ) r = 0;
			if (g > 255) g = 255;
			if (g < 0  ) g = 0;
			if (b > 255) b = 255;
			if (b < 0  ) b = 0;

			*prgb++ = b;
			*prgb++ = g;
			*prgb++ = r;

			r = YCbCrtoR(y1, cb0, cr0);
			g = YCbCrtoG(y1, cb0, cr0);
			b = YCbCrtoB(y1, cb0, cr0);
			if (r > 255) r = 255;
			if (r < 0  ) r = 0;
			if (g > 255) g = 255;
			if (g < 0  ) g = 0;
			if (b > 255) b = 255;
			if (b < 0  ) b = 0;

			*prgb++ = b;
			*prgb++ = g;
			*prgb++ = r;
		}
	}

	if(rgb24){
		*rgb24 = __rgb24.buf;
	}
}

/*RGB24转BMP*/
u32 getbmp24(u8 **bmpaddr, u8 *yuv, u32 w, u32 h)
{
	int len = w*h*3;

	/*yuv4:2:2 ---> rgb24*/
	yuvtorgb24(NULL, yuv, w, h);

	//文件头信息
	BMPFILEHEADER bmpf;
	bmpf.bfType = 0x4D42;
	bmpf.bfSize = sizeof(BMPFILEHEADER)-2 + sizeof(BMPINFOHEADER) + len;
	bmpf.bfReserved = 0;
	bmpf.bfOffBits  = sizeof(BMPFILEHEADER)-2 + sizeof(BMPINFOHEADER);

	//Bitmap头信息
	BMPINFOHEADER bmpi; 
	bmpi.biSize=sizeof(BMPINFOHEADER); 
	bmpi.biWidth=w; 
	bmpi.biHeight=h; 
	bmpi.biPlanes=1; 
	bmpi.biBitCount=24; 
	bmpi.biCompression=0; 
	bmpi.biSizeImage=len; 
	bmpi.biXPelsPerMeter=0; 
	bmpi.biYPelsPerMeter=0; 
	bmpi.biClrUsed=0; 
	bmpi.biClrImportant=0; 
        
        memcpy(__bmp24.buf, &bmpf.bfType, 14);
        memcpy(__bmp24.buf+14, &bmpi, 40);

	u8* prgb24 = __rgb24.buf;
	u8* pbmp   = __bmp24.buf+54;

	memcpy(pbmp, prgb24, sizeof(BMPFILEHEADER)-2 + sizeof(BMPINFOHEADER) + len);

        *bmpaddr = __bmp24.buf;
	return sizeof(BMPFILEHEADER)-2 + sizeof(BMPINFOHEADER) + len;
}

/*RGB TO JPG*/
static u32 rgbtojpeg(u8 **dest, u8 *src, u32 width, u32 height)
{
	struct jpeg_compress_struct cinfo;
	struct jpeg_error_mgr jerr;

	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_compress(&cinfo);

	u32 size = 0;
	jpeg_mem_dest(&cinfo, dest, (long unsigned int *)&size);

	cinfo.image_width  = width; 	
	cinfo.image_height = height;
	cinfo.input_components = 3;		
	cinfo.in_color_space = JCS_RGB; 	

	jpeg_set_defaults(&cinfo);
	jpeg_set_quality(&cinfo, jpeg_quality_scaling(80), TRUE);
	jpeg_start_compress(&cinfo, TRUE);

	u32 row_wide = width*3;

	/*将图像R与B分量互换*/
	u8 rtob;
	for(int i = 0; i < (width*height); i++){
		rtob      = src[i*3];
		src[i*3]  = src[i*3+2];
		src[i*3+2]= rtob;
	}

	JSAMPROW row_pointer[1];	
	while (cinfo.next_scanline < cinfo.image_height) {
		row_pointer[0] = &src[(cinfo.image_height-cinfo.next_scanline-1)*row_wide];
		jpeg_write_scanlines(&cinfo, row_pointer, 1);
	}

	jpeg_finish_compress(&cinfo);
	jpeg_destroy_compress(&cinfo);

	return size;
}

u32 getjpgbuff(u8 **jpgaddr, u8 *yuv, u32 w, u32 h)
{
	pthread_mutex_lock(&mutex);
	
	/*yuv4:2:2 ---> rgb24*/
	yuvtorgb24(NULL, yuv, w, h);
	u32 sz = rgbtojpeg(jpgaddr, __rgb24.buf, w, h);

	pthread_mutex_unlock(&mutex);

	return sz;
}

void freejpgbuff(void *buf)
{
	free(buf);
}


