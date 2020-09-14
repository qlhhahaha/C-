#include"common.h"
#include"forgetp.h"
#include"hz.h"


/*********************************************
FUNCTION:s_1_4
DESCRIPTION：忘记密码界面
INPUT:pagestate
RETURN:无
***********************************************/
void s_1_4(int *pagestate)
{
	int num;
	char U[15] = { '\0' };//用户名
	char P[15] = { '\0' };//11位，电话号码
	char NP[15] = { '\0' };//新密码
	char CP[15] = { '\0' };//确认密码
	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	g_1_4();

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 160 && MouseX < 540 && MouseY>80 && MouseY < 120)
		{
			if (mouse_press(160,80,540,120) == 2)//用户名框未点击
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)//防止被重复标亮
				{
					lightbutton_forget(160,80,540,120, LIGHTCYAN, LIGHTGRAY, 0);//color1为边框色，color2为填充色
					num = 1;
				}
				continue;

				//标亮函数
			}
			else if (mouse_press(160,80,540,120) == 1)//用户名框点击
			{
				MouseS = 0;
				lightbutton_forget(160,80,540,120, LIGHTCYAN, LIGHTGRAY, 0);
				U[0] = '\0';
				inputadmin(U,170,85,11,BLACK);
				if(strlen(U) != 0)
					state1 = 1;	
				else 
					state1 = 0;
				continue;
				//输入函数
			}
		}
		if (MouseX > 160 && MouseX < 540 && MouseY>160 && MouseY < 200)
		{
			if (mouse_press(160,160,540,200) == 2)//电话号未点击
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightbutton_forget(160,160,540,200,LIGHTCYAN, DARKGRAY, 0);//标亮函数
					num = 2;
				}
				continue;
			}
			else if (mouse_press(160,160,540,200) == 1)
			{
				MouseS = 0;
				lightbutton_forget(160,160,540,200, LIGHTCYAN, DARKGRAY, 0);
				P[0] = '\0';
				inputadmin(P, 170,165, 11, BLACK);
				if(strlen(P) != 0)
					state2 = 1;
				else 
					state2 = 0;
				continue;
				//输入函数
			}
		}
		if (MouseX > 160 && MouseX < 540 && MouseY>240 && MouseY < 280)
		{
			if (mouse_press(160,240,540,280) == 2)//新密码框未点击
			{
				MouseS = 2;
				if (num == 0 && state3 == 0)
				{
					lightbutton_forget(160,240,540,280, LIGHTCYAN, DARKGRAY, 0);//标亮函数
					num = 3;
				}
				continue;
			}
			else if (mouse_press(160,240,540,280) == 1)//新密码框点击
			{
				MouseS = 0;
				lightbutton_forget(160,240,540,280, LIGHTCYAN, DARKGRAY, 0);
				NP[0] = '\0';
				inputpassword(NP, 170,245, 16, BLACK);
				if(strlen(NP) != 0)
					state3 = 1;
				else 
					state3 = 0;
				continue;
				//输入函数
			}
		}
		if (MouseX > 160 && MouseX < 540 && MouseY>320 && MouseY <360)
		{
			if (mouse_press(160,320,540,360) == 2)//确认密码框未点击
			{
				MouseS = 2;
				if (num == 0 && state4 == 0)
				{
					lightbutton_forget(160,320,540,360, LIGHTCYAN, DARKGRAY, 0);//标亮函数
					num = 4;
				}
				continue;
			}
			else if (mouse_press(160,320,540,360) == 1)//确认密码框点击
			{
				MouseS = 0;
				lightbutton_forget(160,320,540,360, LIGHTCYAN, DARKGRAY, 0);
				CP[0] = '\0';
				inputpassword(CP, 170,325, 11, BLACK);
				if(strlen(CP) != 0)
					state4 = 1;
				else 
					state4 = 0;
				continue;
				//输入函数

			}
		}
		
		if (MouseX > 250 && MouseX < 410 && MouseY>410 && MouseY < 450)
		{
			if (mouse_press(250,410,410,450) == 2)//完成框未点击
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_forget(250,410,410,450, LIGHTCYAN, DARKGRAY, 1);//标亮函数
					num = 5;
				}
				continue;
			}
			else if (mouse_press(250,410,410,450) == 1)//完成框点击
			{
				MouseS = 0;
				if (forgetpass_complete(U, P, NP, CP))
				{
					*pagestate = 5;
					return;
				}
				else
				{
					continue;
				}
				//检查是否可以修改密码并录入数据库
				//切换至登录界面
			}
		}
		
	
			if (mouse_press(605,5,635,35) == 1)//返回框点击
			{
				MouseS = 0;
				*pagestate = 5;//切换登录界面
				delay(500);
				return;
			}
		}
		
		if (num != 0)
		{
			MouseS = 0;
			if (state1 == 0)
			{
				recoverbutton_forget(1);
			}
			if (state2 == 0)
			{
				recoverbutton_forget(2);
			}
			if (state3 == 0)
			{
				recoverbutton_forget(3);
			}
			if (state4 == 0)
			{
				recoverbutton_forget(4);
			}
			if (num == 5)
			{
				recoverbutton_forget(5);//恢复按钮颜色
			}
			num = 0;
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}

	}

/*********************************************
FUNCTION:lightbutton_forget
DESCRIPTION：忘记密码界面按钮点亮
INPUT:x,y,x1,y1,color1,color2,flag
RETURN:无
***********************************************/
void lightbutton_forget(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框
	switch (flag)
	{
	case 0:
		break;
	case 1:
		puthz(160, 440, "完成", 24, 34, RED);
		break;
		
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}

/*********************************************
FUNCTION:recoverbutton_forget
DESCRIPTION：忘记密码界面按钮恢复
INPUT:status
RETURN:无
***********************************************/
void recoverbutton_forget(int status)
{
	clrmous(MouseX, MouseY);
	setcolor(WHITE);
	if (status == 1 || status == 2|| status==3|| status==4)
	{
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 0, 1);
	}
	else if (status == 5)
	{
		setfillstyle(SOLID_FILL, RED);
	}
	else if (status == 6)
	{
		setfillstyle(SOLID_FILL, BLUE);
	}
	else if (status == 7)
	{
		setfillstyle(SOLID_FILL, CYAN);
	}
	switch (status)
	{
	case 1:
		bar(95, 130, 95 + 450, 130 + 30);
		rectangle(95, 130, 95 + 450, 130 + 30);
		break;
	case 2:
		bar(95, 180 + 30, 95 + 450, 180 + 60);
		rectangle(95, 180 + 30, 95 + 450, 180 + 60);
		break;
	case 3:
		bar(95, 260 + 30, 95 + 450, 260 + 60);
		rectangle(95, 260 + 30, 95 + 450, 260 + 60);
		break;
	case 4:
		bar(95, 340 + 30, 95 + 450, 340 + 60);
		rectangle(95, 340 + 30, 95 + 450, 340 + 60);
		break;
	case 5:
		bar(150, 480 - 10 - 40, 150 + 80, 480 - 10);
		rectangle(150, 480 - 10 - 40, 150 + 80, 480 - 10);
		puthz(160, 440, "完成", 24, 34, WHITE);
		break;
	case 6:
		bar(640 - 100 - 130, 480 - 50, 640 - 150, 480 - 10);
		rectangle(640 - 100 - 130, 480 - 50, 640 - 150, 480 - 10);
		puthz(420, 440, "返回", 24, 34, WHITE);
		break;
	case 7:
		bar(320 - 40, 480 - 50, 320 + 40, 480 - 10);
		rectangle(320 - 40, 480 - 50, 320 + 40, 480 - 10);
		puthz(320 - 30, 440, "重置", 24, 34, WHITE);
		break;
	}
}

/*********************************************
FUNCTION:forgetpass_complete
DESCRIPTION：检查是否可以更改新密码
INPUT:id,ph,np,cp
RETURN:1/0
***********************************************/
int forgetpass_complete(char* id, char* ph, char* np, char* cp)
{
	int st1 = 1;//用户名是否输入的变量
	int st2 = 1;//手机号是否输入的变量
	int st3 = 1;//新密码是否输入的变量
	int st4 = 1;//确认密码是否输入的变量
	int state = 1;//确认密码是否一致的变量
	while (1)
	{
		recoverhz(170, 85, WHITE);//遮盖汉字
		recoverhz(170, 165, WHITE);
		recoverhz(170, 245, WHITE);
		recoverhz(170, 325, WHITE);
		judge(id, &st1, 170, 85); //判断是否输入,未输入会=1
		judge(ph, &st2, 170, 165);
		judge(np, &st3, 170, 245);
		judge(cp, &st4, 170, 325);
		if (st1 == 1 || st2 == 1 || st3 == 1 || st4 == 1)
		{
			break;
		}
		else if (st1 == 0 && st2 == 0 && st3 == 0 && st4 == 0)
		{
			if (judge_sameuser(id,2))//用户名不存在
			{
				puthz(540,85, "用户不存在", 16, 20, RED);
				state = checkright_confirmedpassword(np, cp, 540,245);
				break;
			}
			else if (!judge_sameuser(id,2))//用户名存在
			{
				state= checkright_confirmedpassword(np, cp, 540,245);
				if (!state)
				{
					break;
				}	
				else if (state)
				{
					if (id_phone(id, ph, np, cp))//写入数据库
					{
						return 1;//返回登录界面
					}
					else
					{
						break;
					}
				}
			}
		}
	}
	return 0;
}
