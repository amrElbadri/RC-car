#ifndef _MACROS_H
#define _MACROS_H

#define SET_BIT(reg,Index)  reg|=(1<<Index)
#define CLR_BIT(reg,Index)  reg&=(~(1<<Index))
#define mRP 0 // Right Postive
#define mRN 1 // Right Negative
#define mLP 2 // Left Postive
#define mLN 3 // Left Negative

void forward();
void backward();
void right();
void stop();
void Initpwm();
void Initpwm1();
#endif