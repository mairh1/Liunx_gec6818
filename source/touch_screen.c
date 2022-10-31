/****************************************************************************************
 *设    计:蒋亮
 *日    期:2018-8-26
 *说	明:常用函数
****************************************************************************************/
#include "touch_screen.h"

/*
struct input_event{
	struct timeval time;
	__u16 type;
	__u16 code;
	__s32 value;
};
*/
static int ts_fd;//打开触控屏设备的套接字

/*
	功能：打开触控屏。
	形参：无。
	返回值：成功   0
			失败   -1
*/
int open_ts(void)
{
	ts_fd = open("/dev/input/event0", O_RDWR);
	if(ts_fd == -1)
	{
		printf("open event0 fail!\n");
		return -1;
	}	
	
	return 0;
}

/*
	功能：读取GEC6818触控屏坐标。
	形参：
		int *ts_x：读取x坐标数据。
		int *ts_y：读取y坐标数据。
	返回值：成功   0
			失败   -1	
*/
int read_ts(int *coordinate_x, int *coordinate_y)
{
	int ret;
	struct input_event coordinate;//定义触控屏存储信息结构体，用于存储获取的触控屏信息。
	
	while(1)
	{
		//ssize_t read(int fildes, void *buf, size_t nbyte);
		ret = read(ts_fd, &coordinate, sizeof(struct input_event));//通过read函数存储获取的触控屏信息到coordinate
		if(ret == -1)
		{
			printf("read event0 data fail!\n");
			return 0;
		}
		
		//printf("type:%d code:%d value:%d\n", coordinate.type, coordinate.code, coordinate.value);
		//type:3 code:0 value:607(获取X轴坐标)
		//type:3 code:1 value:254（获取Y轴坐标）
		//type:1 code:330 value:0（松开时退出）
#if  0     //蓝色边框
		if(coordinate.type==EV_ABS && coordinate.code==ABS_X && coordinate.value>0 && coordinate.value<800)//获取X轴坐标
		{
			*coordinate_x = coordinate.value;
		}
		if(coordinate.type==EV_ABS && coordinate.code==ABS_Y && coordinate.value>0 && coordinate.value<480)//获取Y轴坐标
		{
			*coordinate_y = coordinate.value;
		}
#endif
#if  1      //黑色边框
		if(coordinate.type==EV_ABS && coordinate.code==ABS_X && coordinate.value>0 && coordinate.value<1024)//获取X轴坐标
		{
			*coordinate_x = coordinate.value*800/1024;
		}
		if(coordinate.type==EV_ABS && coordinate.code==ABS_Y && coordinate.value>0 && coordinate.value<600)//获取Y轴坐标
		{
			*coordinate_y = coordinate.value*480/600;
		}
#endif
		
		if(coordinate.type==EV_KEY && coordinate.code==BTN_TOUCH && coordinate.value == 0)//退出
		{
			break;
		}				
	}
	
	return 0;
}

/*
	功能：关闭触控屏。
	形参：无。
	返回值：成功   0
			失败   -1
*/
int close_ts(void)
{
	int ret = close(ts_fd);
	if(ret == -1)
	{
		return -1;
	}
		
	return 0;
}