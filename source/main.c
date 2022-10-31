#include "init.h"//init_mmap,
#include "show_bmp.h"
#include "touch_screen.h"

int  my_picture(int *p_main_mmap);
int  resume_browsing(int *p_main_mmap);//�������
int  picture_browsing (int *p_main_mmap);//ͼƬ���

int main(void)
{
	//1-1����ʼ���Դ桢�򿪴�����
	int *p_main_mmap = init_mmap();
	open_ts();
	
	int get_x=0, get_y=0;
	while(1)
	{
		//��ʾ������
		show_1152000bmp("./image/main.bmp", p_main_mmap);
		
		read_ts(&get_x, &get_y);
		printf("(x,y):(%d,%d)\n", get_x, get_y);
		
		if(get_x>100 && get_x<200 && get_y>300 && get_y<400)
		{
			my_picture(p_main_mmap);
		}
		
		
	}
	
	//1-3���ر��Դ棬�رմ�����
	close_mmap(p_main_mmap); 
	close_ts();
	
	return 0;
}

int  my_picture(int *p_main_mmap)
{
	
	int get_x=0, get_y=0;
	while(1)
	{
		//��ʾ����������
		show_1152000bmp("./image/picture.bmp", p_main_mmap);
		
		read_ts(&get_x, &get_y);
		printf("(x,y):(%d,%d)\n", get_x, get_y);
		
		if(get_x>100 && get_x<200 && get_y>300 && get_y<400)//����
		{
			resume_browsing(p_main_mmap);
		}
		
		if(get_x>400 && get_x<700 && get_y>300 && get_y<400)//ͼƬ���
		{
			picture_browsing(p_main_mmap);
		}	
		
		if(get_x>700 && get_x<800 && get_y>400 && get_y<480)//�˳��������
		{
			break;
		}		
				
	}	
	
	return 0;
}


int  resume_browsing(int *p_main_mmap)//�������
{
	int contrl_flag = 0;
	char bmp_path[3][48] = {
		"./image/1.bmp",//bmp_path[0] bmp_path[contrl_flag]
		"./image/2.bmp",//bmp_path[1]
		"./image/3.bmp",//bmp_path[2]
	};
	
	int get_x=0, get_y=0;
	
	//�������
	show_1152000bmp(bmp_path[contrl_flag], p_main_mmap);
	
	while(1)
	{
		
		read_ts(&get_x, &get_y);
		printf("(x,y):(%d,%d)\n", get_x, get_y);
		
		if(get_x>0 && get_x<200 && get_y>0 && get_y<480)//��һ��
		{
			contrl_flag--;//0~2
			if(-1 == contrl_flag)
				contrl_flag = 2;
			
			show_1152000bmp(bmp_path[contrl_flag], p_main_mmap);
			
		}
		
		if(get_x>600 && get_x<800 && get_y>0 && get_y<480)//��һ��
		{
			contrl_flag++;//0~2
			if(3 == contrl_flag)
				contrl_flag = 0;
			
			show_1152000bmp(bmp_path[contrl_flag], p_main_mmap);
			
		}	
		
		if(get_x>200 && get_x<600 && get_y>0 && get_y<480)//�˳��������
		{
			break;
		}		
				
	}	
	
	return 0;
}

int  picture_browsing (int *p_main_mmap)//ͼƬ���
{
	int contrl_flag = 0;
	char bmp_path[3][48] = {
		"./image/4.bmp",//bmp_path[0] bmp_path[contrl_flag]
		"./image/5.bmp",//bmp_path[1]
		"./image/6.bmp",//bmp_path[2]
	};
	
	int get_x=0, get_y=0;
	
	//ͼƬ���
	show_1152000bmp(bmp_path[contrl_flag], p_main_mmap);
	
	while(1)
	{
		
		read_ts(&get_x, &get_y);
		printf("(x,y):(%d,%d)\n", get_x, get_y);
		
		if(get_x>0 && get_x<200 && get_y>0 && get_y<480)//��һ��
		{
			contrl_flag--;//0~2
			if(-1 == contrl_flag)
				contrl_flag = 2;
			
			show_1152000bmp(bmp_path[contrl_flag], p_main_mmap);
			
		}
		
		if(get_x>600 && get_x<800 && get_y>0 && get_y<480)//��һ��
		{
			contrl_flag++;//0~2
			if(3 == contrl_flag)
				contrl_flag = 0;
			
			show_1152000bmp(bmp_path[contrl_flag], p_main_mmap);
			
		}	
		
		if(get_x>200 && get_x<600 && get_y>0 && get_y<480)//�˳�ͼƬ���
		{
			break;
		}	
	
	
	return 0;
}

