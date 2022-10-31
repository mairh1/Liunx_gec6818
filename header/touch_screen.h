/****************************************************************************************
 *设    计:蒋亮
 *日    期:2018-8-26
 *说	明:头文件
****************************************************************************************/
#ifndef __TOUCH_SCREEN_H__
#define __TOUCH_SCREEN_H__

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <linux/input.h>

/*
	功能：打开触控屏。
	形参：无。
	返回值：成功   0
			失败   -1
*/
extern int open_ts(void);

/*
	功能：读取GEC6818触控屏坐标。
	形参：
		int *ts_x：读取x坐标数据。
		int *ts_y：读取y坐标数据。
	返回值：成功   0
			失败   -1	
*/
extern int read_ts(int *ts_x, int *ts_y);

/*
	功能：关闭触控屏。
	形参：无。
	返回值：成功   0
			失败   -1
*/
extern int close_ts(void);

#endif