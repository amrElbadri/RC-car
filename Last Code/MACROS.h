#ifndef _MACROS_H
#define _MACROS_H

#define SET_BIT(reg,Index)  reg|=(1<<Index)
#define CLR_BIT(reg,Index)  reg&=(~(1<<Index))
#define GET_BIT(reg,Index) ((reg>>Index)&0x01)
#define mRP 0 // Right Postive
#define mRN 1 // Right Negative
#define mLP 2 // Left Postive
#define mLN 3 // Left Negative

void forward();
void backward();
void right();
void left();
void stop();
void Initpwm();
void Initpwm1();
void forwardd();
void backwardd();
void rightt();
void leftt();
void rotate(float n);
void Distance(float x);
void squaree();
void circlee1(float x);
void circlee2 (float x);
void infinity(float x);
void cir (float x);
#endif