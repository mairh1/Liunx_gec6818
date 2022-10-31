#include "init.h"//init_mmap,
#include "show_bmp.h"
#include "touch_screen.h"

int  my_picture(int *p_main_mmap);
int  resume_browsing(int *p_main_mmap);//¼òÀúä¯ÀÀ
int  picture_browsing (int *p_main_mmap);//Í¼Æ¬ä¯ÀÀ

int main(void)
{
	//1-1¡¢³õÊ¼»¯ÏÔ´æ¡¢´ò¿ª´¥ÃşÆÁ
	int *p_main_mmap = init_mmap();
	open_ts();
	
	int get_x=0, get_y=0;
	while(1)
	{
		//ÏÔÊ¾Ö÷½çÃæ
		show_1152000bmp("./image/main.bmp", p_main_mmap);
		
		read_ts(&get_x, &get_y);
		printf("(x,y):(%d,%d)\n", get_x, get_y);
		
		if(get_x>100 && get_x<200 && get_y>300 && get_y<400)
		{
			my_picture(p_main_mmap);
		}
		
		
	}
	
	//1-3¡¢¹Ø±ÕÏÔ´æ£¬¹Ø±Õ´¥ÃşÆÁ
	close_mmap(p_main_mmap); 
	close_ts();
	
	return 0;
}

int  my_picture(int *p_main_mmap)
{
	
	int get_x=0, get_y=0;
	while(1)
	{
		//ÏÔÊ¾µç×ÓÏà²á½çÃæ
		show_1152000bmp("./image/picture.bmp", p_main_mmap);
		
		read_ts(&get_x, &get_y);
		printf("(x,y):(%d,%d)\n", get_x, get_y);
		
		if(get_x>100 && get_x<200 && get_y>300 && get_y<400)//¼òÀú
		{
			resume_browsing(p_main_mmap);
		}
		
		if(get_x>400 && get_x<700 && get_y>300 && get_y<400)//Í¼Æ¬ä¯ÀÀ
		{
			picture_browsing(p_main_mmap);
		}	
		
		if(get_x>700 && get_x<800 && get_y>400 && get_y<480)//ÍË³öµç×ÓÏà²á
		{
			break;
		}		
				
	}	
	
	return 0;
}


int  resume_browsing(int *p_main_mmap)//¼òÀúä¯ÀÀ
{
	int contrl_flag = 0;
	char bmp_path[3][48] = {
		"./image/1.bmp",//bmp_path[0] bmp_path[contrl_flag]
		"./image/2.bmp",//bmp_path[1]
		"./image/3.bmp",//bmp_path[2]
	};
	
	int get_x=0, get_y=0;
	
	//¼òÀúä¯ÀÀ
	show_1152000bmp(bmp_path[contrl_flag], p_main_mmap);
	
	while(1)
	{
		
		read_ts(&get_x, &get_y);
		printf("(x,y):(%d,%d)\n", get_x, get_y);
		
		if(get_x>0 && get_x<200 && get_y>0 && get_y<480)//ÉÏÒ»ÕÅ
		{
			contrl_flag--;//0~2
			if(-1 == contrl_flag)
				contrl_flag = 2;
			
			show_1152000bmp(bmp_path[contrl_flag], p_main_mmap);
			
		}
		
		if(get_x>600 && get_x<800 && get_y>0 && get_y<480)//ÏÂÒ»ÕÅ
		{
			contrl_flag++;//0~2
			if(3 == contrl_flag)
				contrl_flag = 0;
			
			show_1152000bmp(bmp_path[contrl_flag], p_main_mmap);
			
		}	
		
		if(get_x>200 && get_x<600 && get_y>0 && get_y<480)//ÍË³ö¼òÀúä¯ÀÀ
		{
			break;
		}		
				
	}	
	
	return 0;
}

int  picture_browsing (int *p_main_mmap)//Í¼Æ¬ä¯ÀÀ
{
	int contrl_flag = 0;
	char bmp_path[3][48] = {
		"./image/4.bmp",//bmp_path[0] bmp_path[contrl_flag]
		"./image/5.bmp",//bmp_path[1]
		"./image/6.bmp",//bmp_path[2]
	};
	
	int get_x=0, get_y=0;
	
	//Í¼Æ¬ä¯ÀÀ
	show_1152000bmp(bmp_path[contrl_flag], p_main_mmap);
	
	while(1)
	{
		
		read_ts(&get_x, &get_y);
		printf("(x,y):(%d,%d)\n", get_x, get_y);
		
		if(get_x>0 && get_x<200 && get_y>0 && get_y<480)//ÉÏÒ»ÕÅ
		{
			contrl_flag--;//0~2
			if(-1 == contrl_flag)
				contrl_flag = 2;
			
			show_1152000bmp(bmp_path[contrl_flag], p_main_mmap);
			
		}
		
		if(get_x>600 && get_x<800 && get_y>0 && get_y<480)//ÏÂÒ»ÕÅ
		{
			contrl_flag++;//0~2
			if(3 == contrl_flag)
				contrl_flag = 0;
			
			show_1152000bmp(bmp_path[contrl_flag], p_main_mmap);
			
		}	
		
		if(get_x>200 && get_x<600 && get_y>0 && get_y<480)//ÍË³öÍ¼Æ¬ä¯ÀÀ
		{
			break;
		}	
	
	
	return 0;
}

