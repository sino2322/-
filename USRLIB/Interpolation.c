#include <servo.h>
#include <Interpolation.h>


//x是基础一步,等同于basic_step,
int f,ye;

int x,xe,y,y0,x0,ref_y,ref_x;
//直线插补的剩余步数
int line_destinaton,x_init_cnt,y_init_cnt;
int x_init_cnt_1,y_init_cnt_1;

void draw_line(float a){
	//only one time
	//move to center
	x_init_cnt=200;
	y_init_cnt=200;
	
	while(x_init_cnt>0){
		fast_step(0,1);
		x_init_cnt--;
	}
	
	while(y_init_cnt>0){
		fast_step(1,1);
		y_init_cnt--;
	}
	
	line_destinaton=500;
	//设定移动后的参考坐标系原点
	ref_y=0;
	ref_x=0;
	
	while(line_destinaton)
	{
		//x,y是当前参考坐标系,只为整
		y=ref_y;
		x=ref_x;
		xe=ref_x;
		ye=a*xe;
		f=(y-y0)*(xe-x0)-(x-x0)*(ye-y0);
		if(f<0){
			//判别函数小于0,y+1
			basic_step(1,1);
			ref_y++;
		}	
		if(f>=0){
			//判别函数大于等于0,x+1
			basic_step(0,1);
			ref_x++;
		}
		line_destinaton--;
	}
}


void draw_circle(){
	int i_next,i_now;
	int j_next,j_now;
	int f_next,f_now;
	
	//run to (200,0)
	//origin is (300,300)
	x_init_cnt_1=500;
	y_init_cnt_1=300;
	
	while(x_init_cnt_1>0){
		fast_step(0,1);
		x_init_cnt_1--;
	}
	
	while(y_init_cnt_1>0){
		fast_step(1,1);
		y_init_cnt_1--;
	}

	j_now=0;
	i_now=200;
	f_now=0;
	
	do{
		if(f_now>=0){
			//在圆外
			if(j_now>=0){
				if(i_now>=0){
					//第一象限，含边沿
					//x-移动
					basic_step(0,0);
					i_next=i_now-1;
					f_next=f_now-2*i_now+1;
				}
				else{
					//第二象限，含x负半轴
					//y_移动
					basic_step(1,0);
					j_next=j_now-1;
					f_next=f_now-2*j_now+1;
				}
			}
			else{
				if(i_now>=0){
					//第四象限，含y负半轴
					//y+移动
					basic_step(1,1);
					j_next=j_now+1;
					f_next=f_now+2*j_now+1;
				}
				else{
					//第三象限，无边沿
					//
					basic_step(0,1);
					i_next=i_now+1;
					f_next=f_now+2*i_now+1;
				}
			}
		}
		//f<0
		//在圆内
		else{
			if(j_now>=0){
				if(i_now>=0){
					//第一象限，含边沿
					//y+移动
					basic_step(1,1);
					j_next=j_now+1;
					f_next=f_now+2*j_now+1;
				}
				else{
					//第二象限，含x负半轴
					//x-移动
					basic_step(0,0);
					i_next=i_now-1;
					f_next=f_now-2*i_now+1;
				}
			}
			else{
				if(i_now>=0){
					//第四象限，含y负半轴
					//x+移动
					basic_step(0,1);
					i_next=i_now+1;
					f_next=f_now+2*i_now+1;
				}
				else{
					//第三象限，无边沿
					//y-移动
					basic_step(1,0);
					j_next=j_now-1;
					f_next=f_now-2*j_now+1;
				}
			}
		}
		
		i_now=i_next;
		j_now=j_next;
		f_now=f_next;
		
	}while(i_now!=200);
}
