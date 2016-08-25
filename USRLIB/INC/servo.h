#ifndef __servo__
#define __servo__

//---8255 hardware settings

//8255 D port == P0

//pin definition
//PA0 X PULSE -> P6 0
//PA1 X DIR   -> P6 1
//PA2 Y PULSE -> P6 2
//PA3 Y DIR   -> P6 3

//WHEN SIG=0 X->X+
//WHEN SIG=1 X->X-
//WHEN SIG=0 Y->Y+
//WHEN SIG=1 Y->Y-

//cfg 8255 A port in output status
void init_8255_AO();
//servo motor run a step with dir
void run_a_step(int,int,int);

void basic_step(int,int);

//void fast_a_step(int,int);

void fast_step(int,int);
#endif