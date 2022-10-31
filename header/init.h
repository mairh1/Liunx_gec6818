/****************************************************************************************
 *设    计:蒋亮
 *日    期:2018-8-26
 *说	明:头文件
****************************************************************************************/
#ifndef __INIT_H__
#define __INIT_H__

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <strings.h>

/*
	功能：GEC6818开发板中DDR3与显存建立映射关系。
	形参：无。			
	返回值：返回映射指针。
*/
extern int *init_mmap(void);

/*
	功能：断开映射关系，释放资源。
	形参：	
		int *end_mmap：映射指针。
	返回值：成功   0
			失败   -1	
*/
extern int close_mmap(int *end_mmap);

#endif