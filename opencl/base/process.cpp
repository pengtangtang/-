/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：process.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年01月12日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>


int main()
{
	/*1：获取平台
	 * 调用clGetPlatformIDs两次，第一次获取可用平台数量，第二次获取一个可用的平台*/
	cl_uint num_platforms;
	int ret;

	ret = clGetPlatformIDs(0,NULL,&num_platforms);
	if((CL_SUCCESS !=ret) || (num_platforms < 1)){
		cout << "Error getting platform number" << ret << endl;
		return -1;
	}

	cl_platform_id platform_id = NULL;
	ret = clGetPlatformIDs(1,&platform_id,NULL);
	if(CL_SUCCESS != ret){
		cout << "Error gettiing platform id." << ret << endl;
		return -1;
	}

	/*2:获取Device
	 * 调用两次clGetDeviceIDs函数，第一次获取可用的设备数量，第二次获取一个可用的设备*/
	cl_uint num_devices;
	ret = clGetDeviceIDs(platform_id,CL_DEVICE_TYPE_GPU,0,NULL,&num_devices);
	if((CL_SUCCESS != ret) || (num_devices < 1)){
		cout << "Error getting GPU device number." << ret << endl;
		return -1;
	}

	cl_device_id device_id = NULL;
	ret = clGetDeviceIDs(platform_id,CL_DEVICE_TYPE_GPU,1,&device_id,NULL);
	if(CL_SUCCESS != ret){
		cout << "Error getting GPU device id." << ret << endl;
		return -1;
	}

	/*3:创建context
	 * 以clCreateContext为例，也可以使用clCreateContextFromType*/
	cl_context_properties props[] = {CL_CONTEXT_PLATFORM,(cl_context_properties)platform_id,0};
	cl_context context = NULL;
	/*properties指定上下文属性名称及其对应值的列表，每一个属性名后面紧跟着相应的所需值，名单终止用0.当属性为空时，选择的平台是实现定义的，CL_CONTEXT_INTEROP_USER_SYNC,指定用户是否负责同步，在opencl和其他api之间*/
	context = clCreateContext(props,1,&device_id,NULL,NULL,&ret);
	if((CL_SCCESS != ret) || (NULL == context)){
		cout << "Error creating context." << ret << endl;
		return -1;
	}

	/*4:创建command queue:
	 * 一个device有多个command queue.把友数据关联的command放到同一个queue里执行，
	 * 没有关联关系的command放到不同的queue.command queue之间并行执行，
	 * 由具体的device来安排*/
	cl_command_queue command_queue = NULL;
	/*第三个参数properties:CL_QUEUE_OUT_OF_OREAD_EXEC_MODE_ENABLE:确定队列是否乱虚执行，若set就
	 * 乱虚执行。CL_QUEUE_PROFILING_ENABLE:是否使命令分析命令队列，若set就启用*/
	command_queue = clCreateCommandQueue(context,device_id,0,&ret);
	if((CL_SUCCESS != ret) || (NULL == command_queue)){
		cout << "Error creating command queue." << ret << endl;
		return -1;
	}

	/*5：创建memory object
	 * buffer和image.buffer由context创建，这样上下文管理的多个设备会共享buffer中的数据。
	 * 注意：CL_MEM_USE_HOST_PTR，内存分配在Host端。理论上device端分配的内存运行更快，但实际应用中往往数据拷贝消耗性能比较多，而使用host端内存能做到类似零拷贝的效果，所以建议将内存分配到host端。有的opencl设备的host与device之间cache交换比较好。*/
	cl_mem mem_obj = NULL;
	int* host_buffer = NULL;
	const int ARRAY_SIZE = 1000;
	const int BUF_SIZE = ARRAY_SIZE*sizeof(int);

	mem_obj = clCreateBuffer(context,CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR,BUF_SIZE,host_buffer,&ret);
	if((CL_SUCCESS != ret) || (NULL == mem_obj)){
		cout << "Error creating command queue." << ret << endl;
		return -1;
	}

	/*6:创建和编译program
	 * 程序对象可以从源文件或二进制文件创建。都需要经过编译才能使用。对于二进制文件build更像程序加载过程*/
	char* kernelSource = 
	"_kernel void test(_global int *pinOut)\n"
	"{\n"
	"int index = get_global_id(0);\n"
	"pinOut[index] += pinOut[index];\n"
	"}\n";

	cl_program program = NULL;
	/*为上下文创建程序对象，并加载文本字符串中指定的源代码*字符串数组进入程序对象
	 * 第二个参数count：需要多少个源程序,即strings的元素个数，第三个参数：strings,第4个参数：lengths，为数组其中元素代表第三个参数中各字符串长度，当其中一个元素为0时，表示其对应的kernelsource is null-terminated.若length == NULL
	 * ,表示所有的strings argument are null-terminatede.*/
	program = clCreateProgramWithSOurce(context,1,(const char**)kernelSource,NULL,&ret);
	if((CL_SUCCESS != ret) || (NULL == program)){
		cout << "Error creating program." << ret << endl;
		return -1;
	}
	ret = clBuildProgram(program,1,&device_id,NULL,NULL,NULL);
	if(CL_SUCCESS != ret){
		cout << "Error building program." << ret << endl;
		return -1;
	}

	/*7:创建kernel
	 * 从program对象生成kernel对象，表示设备程序的入口。*/
	cl_kernel kernel = NULL;
	kernel = clCreateKernel(program,"test",&ret);
	if((CL_SUCCESS != ret) || (NULL == kernel)) {
		cout << "Error creating kernel" << ret << endl;
		return -1;
	}

	/*8:设置kernel参数*/
	ret = clSetKernelArg(kernel,0,sizeof(cl_mem),(void *)&mem_obj);
	if(CL_SUCCESS != ret){
		cout << "error setting kernel argument." << ret << endl;
		return -1;
	}

	/*9：设置group size
	 * 一个opencl运行任务中并行计算的单位是work_item.由global_work_size 和local_work_size决定
	 * opencl支持的最大维数是3--CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS获取，local_work_size与具体的设备有关*/
	cl_uint work_dim = 3;
	size_t global_work_size[] = {ARRAY_SIZE,1,1};
	size_t* local_work_size = NULL;

	/*10：kernel入队执行*/
	ret = clEnqueueNDRangeKernel(command_queue,kernel,work_dim,NULL,global_work_size,local_work_size,0,NULL,NULL);
	if(CL_SUCCESS != ret){
		cout << "Error enqueue NDRange." << ret << endl;
		return -1;
	}

	/*11:读取结果
	 * clEnqueueMapBuffer读取，这样当内存分配在host端，map操作只需将device cache中的内容同步到host内存，不许要内存拷贝。所消耗的时间比clEnqueueReadBuffer小*/

	int *device_buffer = (int *)clEnqueueMapBuffer(command_queue,mem_obj,CL_TRUE,CL_MAP_READ | CL_MAP_WRITE,0,BUF_SIZE,0,NULL,NULL,&ret);
	if((CL_SUCCESS != ret) || (NULL == device_buffer)){
		cout << "Error map buffer." << ret << endl;
		return -1;
	}

	/*12:释放资源*/
	if(NULL != kernel) 	clReleaseKernel(kernel);
	if(NULL != program) 	clReleaseProgram(program);
	if(NULL != mem_obj) 	clReleaseMemObject(mem_obj);
	if(NULL != command_queue) 	clReleaseCOmmandQueue(command_queue);

	return 0;
}
