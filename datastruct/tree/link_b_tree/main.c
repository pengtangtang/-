/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：main.c
*   创 建 者：pengtangtang
*   创建日期：2019年11月05日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "link_tree.h"

int main()
{
	bir_thr_tree root = create_bir_tree(1,8);
	in_threading(root);
	return 0;
}
