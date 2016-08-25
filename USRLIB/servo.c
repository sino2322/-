#include <common.h>

int basic_step_cnt=100;
int b_step_cnt,f_step_cnt;

void init_8255_AO(){
	com_8255=mode_8255;
}

void run_a_step(int row,int dir,int speed){
	if(row==1&&dir==0){
		//y row move a step
			//fan_zhuan flag
			A_8255=0x01;
			delay(speed);
			A_8255=0x03;
			delay(speed);
			return;
	}
	if(row==1&&dir==1){
			//zheng_zhuan flag
			A_8255=0x00;
			delay(speed);
			A_8255=0x02;
			delay(speed);
		return;
	}
	if(row==0&&dir==0){
		//x row move a step
			//fan_zhuan flag
			A_8255=0x04;
			delay(speed);
			A_8255=0x0c;
			delay(speed);
		return;
	}
	if(row==0&&dir==1){
			//zheng_zhuan flag
			A_8255=0x00;
			delay(speed);
			A_8255=0x08;
			delay(speed);
		return;
	}
}

//void real_step()

void basic_step(int b_row,int b_dir){
	for(b_step_cnt=basic_step_cnt;b_step_cnt>0;b_step_cnt--){
			run_a_step(b_row,b_dir,10);
			b_step_cnt--;
	}
}
		
void fast_step(int f_row,int f_dir){
	for(f_step_cnt=basic_step_cnt;f_step_cnt>0;f_step_cnt--){
			run_a_step(f_row,f_dir,4);
			f_step_cnt--;
	}
}
