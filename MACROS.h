#ifndef _MACROS_H
#define _MACROS_H
#define SET_BIT(reg,Index)  reg|=(1<<Index)
#define CLR_BIT(reg,Index)  reg&=(~(1<<Index))
void forward();
void backward();
void right();
void stop();
#endif