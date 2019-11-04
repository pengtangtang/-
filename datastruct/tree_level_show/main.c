/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：main.c
*   创 建 者：pengtangtang
*   创建日期：2019年08月09日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "linktree.h"

int main()
{
	tree *root=createtree(1,12);
	priorder(root);
	printf("\n");
	tree_level_show(root);
	return 0;
}
