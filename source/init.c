/****************************************************************************************
 *设    计:蒋亮
 *日    期:2018-8-26
 *说	明:常用函数
****************************************************************************************/
#include "init.h"

/*
	功能：GEC6818开发板中DDR3与显存建立映射关系。
	形参：无。			
	返回值：返回映射指针。
*/
int *init_mmap(void)
{
	int file_fd = open("/dev/fb0", O_RDWR);//打开LCD显示屏
	if(file_fd == -1)
	{
		printf("open /dev/fb0 fail!\n");
		return NULL;
	}	
		
	int *init_mmap_fd = malloc(sizeof(int *));//定义映射指针，建立映射关系。
	init_mmap_fd = mmap(NULL, 800*480*4, PROT_READ|PROT_WRITE,  MAP_SHARED, file_fd, 0);
	if(init_mmap_fd == MAP_FAILED)
	{
		printf("mmap lcd fail!\n");
		return NULL;
	}
	
	return init_mmap_fd;
}

/*
	功能：断开映射关系，释放资源。
	形参：	
		int *end_mmap：映射指针。
	返回值：成功   0
			失败   -1	
*/
int close_mmap(int *end_mmap)
{
	int ret = munmap(end_mmap, 800*480*4);//断开映射关系，释放资源。	
	if(ret == -1)
	{
		return -1;
	}
	
	return 0;
}
