#include <common.h>

//unsigned char num,temp;
	 
//void main()
//{
//	unsigned char key,num=16;3
//	com_8255=mode_8255; //8255的控制方式
//	P2=0xff;  //1数码管亮 按相应的按键，会显示对应字符
//	B_8255=dofly[16];
//	while(1)
//	{
//		key=keyscan();//调用键盘扫描，
//		B_8255=dofly[key];
//	}
//}

unsigned char keyscan()
{
	unsigned char num,temp;
	C_8255=0x7f;//第一列，0,4,8,c
	temp=C_8255;
	temp=temp&0x0f;
	while(temp!=0x0f)
	{
		slow_delay(5);
		temp=C_8255;
		temp=temp&0x0f;
		while(temp!=0x0f)
		{
			temp=C_8255;
			switch(temp)
			{
				case 0x7e:num=0;
					break;
				case 0x7d:num=4;
					break;
				case 0x7b:num=8;
					break;
				case 0x77:num=12;
					break;
			}
			while(temp!=0x0f)
			{
				temp=C_8255;
				temp=temp&0x0f;
			}
		}
	}	
	C_8255=0xbf;//第二列，1,5,9,d
	temp=C_8255;
	temp=temp&0x0f;
	while(temp!=0x0f)
	{
		slow_delay(5);
		temp=C_8255;
		temp=temp&0x0f;
		while(temp!=0x0f)
		{
			temp=C_8255;
			switch(temp)
			{
				case 0xbe:num=1; 
					break;
				case 0xbd:num=5; 
					break;
				case 0xbb:num=9; 
					break;
				case 0xb7:num=13; 
					break;
			}
			while(temp!=0x0f)
			{
				temp=C_8255;
				temp=temp&0x0f;
			}
		}
	}	
	C_8255=0xdf;//第三列，2,6,a,e
	temp=C_8255;
	temp=temp&0x0f;
	while(temp!=0x0f)
	{
		slow_delay(5);
		temp=C_8255;
		temp=temp&0x0f;
		while(temp!=0x0f)
		{
			temp=C_8255;
			switch(temp)
			{
				case 0xde:num=2;
					break;
				case 0xdd:num=6;
					break;
				case 0xdb:num=10;
					break;
				case 0xd7:num=14;
					break;
			}
			while(temp!=0x0f)
			{
				temp=C_8255;
				temp=temp&0x0f;
			}
		}
	}	
	C_8255=0xef;//第四列，3,7,b,f
	temp=C_8255;
	temp=temp&0x0f;
	while(temp!=0x0f)
	{
		slow_delay(5);
		temp=C_8255;
		temp=temp&0x0f;
		while(temp!=0x0f)
		{
			temp=C_8255;
			switch(temp)
			{
				case 0xee:num=3;
					break;
				case 0xed:num=7;
					break;
				case 0xeb:num=11;
					break;
				case 0xe7:num=15;
					break;
			}
		    while(temp!=0x0f)
			{
				temp=C_8255;
				temp=temp&0x0f;
			}
		}
	}
	return num;
}

