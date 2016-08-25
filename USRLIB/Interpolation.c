#include <servo.h>
#include <Interpolation.h>


//x�ǻ���һ��,��ͬ��basic_step,
int f,ye;

int x,xe,y,y0,x0,ref_y,ref_x;
//ֱ�߲岹��ʣ�ಽ��
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
	//�趨�ƶ���Ĳο�����ϵԭ��
	ref_y=0;
	ref_x=0;
	
	while(line_destinaton)
	{
		//x,y�ǵ�ǰ�ο�����ϵ,ֻΪ��
		y=ref_y;
		x=ref_x;
		xe=ref_x;
		ye=a*xe;
		f=(y-y0)*(xe-x0)-(x-x0)*(ye-y0);
		if(f<0){
			//�б���С��0,y+1
			basic_step(1,1);
			ref_y++;
		}	
		if(f>=0){
			//�б������ڵ���0,x+1
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
			//��Բ��
			if(j_now>=0){
				if(i_now>=0){
					//��һ���ޣ�������
					//x-�ƶ�
					basic_step(0,0);
					i_next=i_now-1;
					f_next=f_now-2*i_now+1;
				}
				else{
					//�ڶ����ޣ���x������
					//y_�ƶ�
					basic_step(1,0);
					j_next=j_now-1;
					f_next=f_now-2*j_now+1;
				}
			}
			else{
				if(i_now>=0){
					//�������ޣ���y������
					//y+�ƶ�
					basic_step(1,1);
					j_next=j_now+1;
					f_next=f_now+2*j_now+1;
				}
				else{
					//�������ޣ��ޱ���
					//
					basic_step(0,1);
					i_next=i_now+1;
					f_next=f_now+2*i_now+1;
				}
			}
		}
		//f<0
		//��Բ��
		else{
			if(j_now>=0){
				if(i_now>=0){
					//��һ���ޣ�������
					//y+�ƶ�
					basic_step(1,1);
					j_next=j_now+1;
					f_next=f_now+2*j_now+1;
				}
				else{
					//�ڶ����ޣ���x������
					//x-�ƶ�
					basic_step(0,0);
					i_next=i_now-1;
					f_next=f_now-2*i_now+1;
				}
			}
			else{
				if(i_now>=0){
					//�������ޣ���y������
					//x+�ƶ�
					basic_step(0,1);
					i_next=i_now+1;
					f_next=f_now+2*i_now+1;
				}
				else{
					//�������ޣ��ޱ���
					//y-�ƶ�
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
