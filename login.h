#ifndef _login_h
#define _login_h
#include"database.h"

void s_1(int *pagestate);
void s_0_1(int *pagestate);
void s_0_2(int *pagestate);
void s_1_1(int *pagestate);
void s_1_2_1(int *pagestate,USER *u);
void s_1_2_2(int *pagestate);
void lightbutton_login(int x, int y, int x1, int y1, int color1, int color2, int flag);
void recoverbutton_login(int status);
#endif