#include <stdio.h>
#include <assert.h>
#define TRUE 1
#define FALSE 0

int a=0;
int b=1;
int c=2;
int e=3;
int f=4;
int g=5;
int wf0=6;
int wf1=7;

struct state_elements_main {
  _Bool OUTP, OVERFLW;
  _Bool stato;
};
struct state_elements_main smain; 

void initial() {
	smain.stato = a;
	smain.OUTP = 0;
	smain.OVERFLW = 0;
}

void b01(
  _Bool  LINE1, _Bool LINE2,
  _Bool *OUTP, _Bool *OVERFLW, 
  _Bool  clock)
{
  // clocked block
  switch(smain.stato) {
    case a: {
              if (LINE1 & LINE2)
                smain.stato = f;
              else
                smain.stato = b;
              smain.OUTP = LINE1 ^ LINE2;
              smain.OVERFLW = 0;
              break;
            }
    case e: {
              if (LINE1 & LINE2)
                smain.stato = f;
              else
                smain.stato = b;
              smain.OUTP = LINE1 ^ LINE2;
              smain.OVERFLW = 1;
              break;
            }
    case b: {
              if (LINE1 & LINE2)
                smain.stato = g;
              else 
                smain.stato = c;
              smain.OUTP = LINE1 ^ LINE2;
              smain.OVERFLW = 0;
              break;
            }
    case f: {
              if (LINE1 | LINE2)
                smain.stato = g;
              else
                smain.stato = c;
              smain.OUTP = ~(LINE1 ^ LINE2);
              smain.OVERFLW = 0;
              break;
            }
    case c: {
              if (LINE1 & LINE2)
                smain.stato = wf1;
              else
                smain.stato = wf0;
              smain.OUTP = LINE1 ^ LINE2;
              smain.OVERFLW = 0;
              break;
            }
    case g: {
              if (LINE1 | LINE2)
                smain.stato = wf1;
              else
                smain.stato = wf0;
              smain.OUTP = ~(LINE1 ^ LINE2);
              smain.OVERFLW = 0;
              break;
            }
    case wf0: {
                if (LINE1 & LINE2)
                  smain.stato = e;
                else
                  smain.stato = a;
                smain.OUTP = LINE1 ^ LINE2;
                smain.OVERFLW = 0;
                break;
              }
    case wf1: {
                if (LINE1 | LINE2)
                  smain.stato = e;
                else             
                  smain.stato = a;
                smain.OUTP = ~(LINE1 ^ LINE2);
                smain.OVERFLW = 0;
                break;
              }
  }
  *OUTP=smain.OUTP;
  *OVERFLW=smain.OVERFLW;
}
 
void main()
{
 
  _Bool  LINE1; _Bool LINE2;
  _Bool OUTP; _Bool OVERFLW; 
  _Bool  clock;
 initial();
 while(1) {
   b01(LINE1,LINE2,&OUTP,&OVERFLW,clock);
   if(smain.OVERFLW==1) {
     b01(LINE1,LINE2,&OUTP,&OVERFLW,clock);
     b01(LINE1,LINE2,&OUTP,&OVERFLW,clock);
     assert(smain.OVERFLW==0);
   }
   assert(smain.stato!=wf0);
 }
}



