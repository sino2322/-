#include <common.h>

int x_row=0;
int y_row=1;
unsigned int i,j,k;

unsigned int arrive_center;
unsigned int center_default=3600*20;

extern int global_speed;

void all_task_init(){
	int init_loop=20000;
	while(init_loop){
		run_a_step(0,0,1);
		run_a_step(1,0,1);
		init_loop--;
	}
}

/*
param:	xx -> x row dir , when xx = -1 disable x row
				yy -> y row dir , when yy = -1 disable y row
				sp -> speed
				test_loop_core -> real step
*/
void simple_test(int xx,int yy,int sp,int test_loop_core){
//	schedule_init();
	//default value
	if(!test_loop_core)
		test_loop_core=200;
	
	if(xx==-1){
		for(i=200;i>0;i--){
			for(k=test_loop_core;k>0;k--)
				run_a_step(y_row,yy,sp);
		}
	}
	if(yy==-1){
		for(i=200;i>0;i--){
			for(j=test_loop_core;j>0;j--)
				run_a_step(x_row,xx,sp);
		}
	}
}

void cfg_speed_adjust(){
	if(keyscan()==13){
						//speed up
						if(global_speed>1)
							global_speed--;
					}
					if(keyscan()==14){
						//slow down
						if(global_speed<10)
							global_speed++;
					}
}



//void mov_with_cfg_speed_adjust_key_4(){
//	int default_speed=5;
//	unsigned char key_sp_adj,key_sp_adj_1=16;
//	key_sp_adj=keyscan();
//	if(keyscan()!=4){
//		key_sp_adj=keyscan();
//	}
//		
//	while(1){
//			switch (key_sp_adj){
//				case 8:
//					//row +
//					if(default_speed<10)
//						default_speed++;
//						simple_test(1,-1,default_speed,1);
//				break;
//				case 9:
//					//row -
//					if(default_speed<10)
//							default_speed++;
//						simple_test(1,-1,default_speed,1);
//				break;
//				default:
//				break;
//			}
//	}
//}
