#include <delay.h>

int count_set=7;
int quick_set=2;
int slow_set=50;

static int count,count1;

void delay(count1){
	count=count_set;
	for(;count1>0;count1--)
		for(;count>0;count--);
}	

void quick_delay(count1){
	count=quick_set;
	for(;count1>0;count1--)
		for(;count>0;count--);
}	

void slow_delay(count1){
	count=slow_set;
	for(;count1>0;count1--)
		for(;count>0;count--);
}
