/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：test.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年01月09日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define PROGRAM_FILE "id_check.cl"
#define KERNEL_FUNC "id_check"
#ifdef MAC
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif

cl_device_id create_device()
{
	cl_platform_id platform;
	cl_device_id dev;
	int err;

	err = clGetPlatformIDs(1,&platform,NULL);
	if(err < 0){
		perror("could not identify a platform");
		exit(1);
	}

	err = clGetDeviceIDs(platform,CL_DEVICE_TYPE_GPU,1,dev,NULL);
	if(err == CL_DEVICE_NOT_FOUND){
		err = clGetDeviceIDs(platform,CL_DEVICE_TYPE_CPU,1,&dev,NULL);;
	}
	if(err < 0){
		perror("could not access any device");
		exit(1);
	}
	return dev;
}

cl_program build_program(cl_context ctx,cl_device_id dev,const char* filename)
{
	cl_program program;
	FILE* program_handle;
	char *program_buffer,*program_log;
	size_t program_size,log_size;
	int err;

	program_handle = fopen(filename,"r");
	if(program_handle == NULL){
		perror("could not find the program file");
		exit(1);
	}

	fseek(program_handle,0,SEEK_END);
	program_size = ftell(program_handle);
	rewind(program_handle);
	program_buffer = (char *)malloc(program_size + 1);
	program_buffer[program_size] = '\0';
	fread(program_buffer,sizeof(char),program_size,program_handle);
	fclose(program_handle);

	program = clCreateProgramWithS
}

int main()
{
	cl_device_id device;
	cl_context context;
	cl_command_queue queue;
	cl_program program;
	cl_kernel kernel;
	cl_int i,err;

	size_t dim = 2;
	size_t global_offset[] = {3,5};
	size_t global_size[] = {6,4};
	size_t local_size[] = {3,2};
	float test[24];
	cl_mem test_buffer;

	device = create_device();

	//属性列表，设备数量，设备列表，回调函数，提供报错信息，错误信息大小
	context = clCreateContext(NULL,1,&device,NULL,NULL,&err);
	if(err < 0){
		perror("could not create a context");;
		exit(1);
	}

	program = build_program(context,device,PROGRAM_FILE);

	kernel = clCreateKernel(program,KERNEL_FUNC,&err);
	if(err < 0){
		perror("could not create a kernel");
		exit(1);
	}

	test_buffer = clCreateBuffer(contex,CL_MEM_WRITE_ONLY,sizeof(test),NULL,&err);
	if(err < 0){
		perror("could not create a kernel");
		exit(1);
	}

	err = clSetKernelArg(kernel,0,sizeof(cl_mem),&test_buffer);
	if(err < 0){
			perror("could not set a kernel argument");
			exit(1);
	}

	err = clEnqueueReadBuffer(queue,test_buffer,CL_TRUE,0,sizeof(test),
			&test,0,NULL,NULL);
	if(err < 0){
		perror("could not read the buffer");
		exit(1);
	}

	for(i = 0;i < 24;i += 6){
		printf("%.2f	%.2f	%.2f	%.2f	%.2f	%.2f\n",test[i],test[i+1],test[i+2],test[i+3],test[i+4],test[i+5]);
	}

	clReaseMemObject(test_buffer);
	clRealseKernel(kernel);
	clReaseCommandQueue(queue);
	clReaseProgram(program);
	clReaseContext(context);
	return 0;
}
