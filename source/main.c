#include "init.h"//init_mmap,
#include "show_bmp.h"
#include "touch_screen.h"

int  my_picture(int *p_main_mmap);
int  resume_browsing(int *p_main_mmap);//简历浏览
int  picture_browsing (int *p_main_mmap);//图片浏览

int main(void)
{
	//1-1、初始化显存、打开触摸屏
	int *p_main_mmap = init_mmap();
	open_ts();
	
	int get_x=0, get_y=0;
	while(1)
	{
		//显示主界面
		show_1152000bmp("./image/main.bmp", p_main_mmap);
		
		read_ts(&get_x, &get_y);
		printf("(x,y):(%d,%d)\n", get_x, get_y);
		
		//点击相册控件
		if(get_x>100 && get_x<200 && get_y>300 && get_y<400)
		{
			my_picture(p_main_mmap);
		}
		
		
	}
	
	//1-3、关闭显存，关闭触摸屏
	close_mmap(p_main_mmap); 
	close_ts();
	
	return 0;
}

int  my_picture(int *p_main_mmap)
{
	
	int get_x=0, get_y=0;
	while(1)
	{
		//显示电子相册界面
		show_1152000bmp("./image/picture.bmp", p_main_mmap);
		
		read_ts(&get_x, &get_y);
		printf("(x,y):(%d,%d)\n", get_x, get_y);
		
		if(get_x>100 && get_x<200 && get_y>300 && get_y<400)//简历
		{
			resume_browsing(p_main_mmap);
		}
		
		if(get_x>400 && get_x<700 && get_y>300 && get_y<400)//图片浏览
		{
			picture_browsing(p_main_mmap);
		}	
		
		if(get_x>700 && get_x<800 && get_y>400 && get_y<480)//退出电子相册
		{
			break;
		}		
				
	}	
	
	return 0;
}


int  resume_browsing(int *p_main_mmap)//简历浏览
{
	int contrl_flag = 0;
	char bmp_path[3][48] = {
		"./image/1.bmp",//bmp_path[0] bmp_path[contrl_flag]
		"./image/2.bmp",//bmp_path[1]
		"./image/3.bmp",//bmp_path[2]
	};
	
	int get_x=0, get_y=0;
	
	//简历浏览，默认显示简历一这么一张图片
	show_1152000bmp(bmp_path[contrl_flag], p_main_mmap);
	
	while(1)
	{
		
		read_ts(&get_x, &get_y);
		printf("(x,y):(%d,%d)\n", get_x, get_y);
		
		if(get_x>0 && get_x<200 && get_y>0 && get_y<480)//上一张
		{
			contrl_flag--;//0~2
			if(-1 == contrl_flag)
				contrl_flag = 2;
			
			show_1152000bmp(bmp_path[contrl_flag], p_main_mmap);
			
		}
		
		if(get_x>600 && get_x<800 && get_y>0 && get_y<480)//下一张
		{
			contrl_flag++;//0~2
			if(3 == contrl_flag)
				contrl_flag = 0;
			
			show_1152000bmp(bmp_path[contrl_flag], p_main_mmap);			
		}	
		
		if(get_x>200 && get_x<600 && get_y>0 && get_y<480)//退出简历浏览
		{
			break;
		}		
				
	}	
	
	return 0;
}

int  picture_browsing (int *p_main_mmap)//图片浏览
{
	//每隔1s显示1张图片
	pic_circular_spread("./image/4.bmp", p_main_mmap);sleep(1);
	
	pic_circular_spread("./image/5.bmp", p_main_mmap);sleep(1);
	
	pic_circular_spread("./image/6.bmp", p_main_mmap);sleep(1);
	
	return 0;
}

