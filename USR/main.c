#include <common.h>

int global_speed;

void main(){
	
	init_8255_AO();
	//simple_test(-1,0,8,100);
	//draw_line(1);
	//all_task_init();
	//draw_circle();
	
	global_speed=5;
	while(1)
	{
		unsigned char key=16;
		key=keyscan();//µ˜”√º¸≈Ã…®√Ë£¨
		switch (key)
		{
			case 1:
				//come back to physical zero
				all_task_init();
				break;
			case 2:
				//draw a line
				draw_line(0.5);
				break;
			case 3:
				//draw a circle
				draw_circle();
				break;
			
			
			case 5:
				//move with adjustable speed x+
				while(1){
					simple_test(1,-1,global_speed,1);
					if(keyscan()==7)
						break;				
					if(keyscan()==6)
						break;
					if(keyscan()==9)
						break;	
					if(keyscan()==10)
						break;	
					cfg_speed_adjust();
				}
				break;
			case 6:
				//move with adjustable speed x-
				while(1){
					simple_test(0,-1,global_speed,1);
					if(keyscan()==7)
						break;
					if(keyscan()==5)
						break;
					if(keyscan()==9)
						break;	
					if(keyscan()==10)
						break;	
					cfg_speed_adjust();
				}
				break;
			case 9:
				//move with adjustable speed y+
				while(1){
					simple_test(-1,1,global_speed,1);
					if(keyscan()==7)
						break;
					if(keyscan()==6)
						break;
					if(keyscan()==5)
						break;	
					if(keyscan()==10)
						break;	
					cfg_speed_adjust();
				}
				break;
			case 10:
				//move with adjustable speed y-
				while(1){
					simple_test(-1,0,global_speed,1);
					if(keyscan()==7)
						break;
					if(keyscan()==6)
						break;
					if(keyscan()==9)
						break;	
					if(keyscan()==5)
						break;	
					cfg_speed_adjust();
				}
				break;
			default:
				break;
		}
	}
	while(1);
}