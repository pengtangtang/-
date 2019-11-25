/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：main.c
*   创 建 者：pengtangtang
*   创建日期：2019年11月02日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "m_c.h"
#include <dlfcn.h>

int main()
{
	//test();
	
	printf("start to call test\n");
	char *error = NULL;
	/*打开动态库*/
	void *handle = dlopen("libm_c.so",RTLD_LAZY);/*使用dlopen打开动态库*/
	if(NULL == handle)
	{
		error = dlerror();
		printf("open error:%s",error);
		return -1;
	}

	/*返回类型为函数指针*/
	void (*fun)() = dlsym(handle,"m_c");/*使用dlsym找到需要使用的符号*/
	if(NULL == fun)
	{
		error = dlerror();
		printf("open error:%s",error);
		dlclose(handle);
		return -1;
	}
	/*调用函数*/
	(*fun)();

	/*关闭*/
	dlclose(handle);
	printf("end to call test\n");
	return 0;
	m_c();
	return 0;
}
