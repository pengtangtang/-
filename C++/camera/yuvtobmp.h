/*
 * YUYV转换成bmp模块
 */
#ifndef YUVTOBMP_H
#define YUVTOBMP_H

#include <mytypes.h>

/*
 *功能：YUYV转RGB16函数
 *输入：
 *	rgb24 - 得到指向保存rgb24首地址的指针（输出）
 *	yuv - yuv4:2:2首地址
 *	w   - 宽 
 *	h   - 高
 *输出：
 *	无
 */
void yuvtorgb16(u16**rgb16, u8 *yuv, u32 w, u32 h);

/*
 *功能：YUYV转RGB24函数
 *输入：
 *	rgb24 - 得到指向保存rgb24首地址的指针（输出）
 *	yuv - yuv4:2:2首地址
 *	w   - 宽 
 *	h   - 高
 *输出：
 *	无
 */
void yuvtorgb24(u8**rgb24, u8 *yuv, u32 w, u32 h);

/*
 *RGB16转BMP
 *输入：
 *	bmpaddr - 得到指向保存bmp首地址的指针（输出）
 *	yuv - yuv4:2:2首地址
 *	w   - 宽 
 *	h   - 高
 *输出：
 *	bmp文件长度
 */
u32 getbmp16(u8 **bmpaddr, u8 *yuv, u32 w, u32 h);

/*
 *RGB24转BMP
 *输入：
 *	bmpaddr - 得到指向保存bmp首地址的指针（输出）
 *	yuv - yuv4:2:2首地址
 *	w   - 宽 
 *	h   - 高
 *输出：
 *	bmp文件长度
 */
u32 getbmp24(u8 **bmpaddr, u8 *yuv, u32 w, u32 h);

/*
 *RGB24转JPG
 *输入：
 *	jpgaddr - 得到指向保存jpg首地址的指针（输出）
 *	yuv - yuv4:2:2首地址
 *	w   - 宽 
 *	h   - 高
 *输出：
 *	jpg文件长度
 */
u32 getjpgbuff(u8 **jpgaddr, u8 *yuv, u32 w, u32 h);

void freejpgbuff(void *buf);

/*
 * 初始化及分配空间
 *输入：
 *	w   - 宽 
 *	h   - 高
 *输出：
 *	无
 */
void init_conv(u32 w, u32 h);

/*回收空间*/
void uninit_conv(void);

#endif
