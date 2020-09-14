#include"common.h"
#include"drawfun.h"
#include"login.h"
#include"drawpage.h"
#include"loginfun.h"
#include"hz.h"

void s_1(int *pagestate)
{
	g_1();//欢迎页面1绘图函数
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if (mouse_press(30,300,180,360)==1)
		{
			*pagestate=4;//登陆，身份选择
			return;
		}
		if (mouse_press(245,300,395,360)==1)
		{
			*pagestate=2;//使用说明
			return;
		}
		if (mouse_press(460,300,610,360)==1)
		{
			*pagestate=3;//关于我们
			return;
		}
		if (mouse_press(605,5,635,35)==1)
		{
			*pagestate=1;//退出
			delay(500);
			return;
		}
	}
}

void s_0_1(int *pagestate)
{
	
}

void s_0_2(int *pagestate)
{
	
}

void s_1_1(int *pagestate)
{
	cleardevice();
	g_1_1();//身份选择页面1_1绘图函数
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if (mouse_press(240,170,400,220)==1)
		{
			*pagestate=5;//个人登陆页面
			return;
		}
		if (mouse_press(240,260,400,310)==1)
		{
			*pagestate=5;//团体登陆页面
			return;
		}
		if (mouse_press(240,350,400,400)==1)
		{
			*pagestate=6;//管理员登陆页面
			return;
		}
		if (mouse_press(605,5,635,35)==1)
		{
			*pagestate=0;//返回标题页面
			delay(500);
			return;
		}
	}
}

/**********************************************
FUNCTION:s_1_2_1
DESCRIPTION：用户（包括个人和团体）登录界面控制
INPUT:pagestate,u
RETURN:无
***********************************************/
void s_1_2_1(int *pagestate,USER *u)
{
	int num;
	int state1 = 0;
	int state2 = 0;
	memset(u,'\0',sizeof(USER));   //将别处传过来的u清零
	clrmous(MouseX, MouseY);
	delay(100);
	g_1_2();

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX >100 && MouseX < 540 && MouseY>100 && MouseY < 150)
		{
			if (mouse_press(100,100,540,150) == 2)//用户名框未点击
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)//防止被重复标亮
				{
					lightbutton_login(100,100,540,150, LIGHTCYAN, LIGHTGRAY, 1);//color1为边框色，color2为填充色
					num = 1;
				}
				continue;
				//标亮函数
			}

			else if (mouse_press(100,100,540,150) == 1)//用户名框点击
			{
				MouseS = 0;
				lightbutton_login(100,100,540,150, LIGHTCYAN, LIGHTGRAY, 1);
				u->userid[0] = '\0';
				inputadmin(u->userid,120,110,11, LIGHTGRAY);//输入的字符串，输入的xy，输入的字符限制，输入框的颜色
				//输入函数
				if(strlen(u->userid) != 0)
					state1 = 1;
				else 
					state1 = 0;
				continue;
			}
		}
		
		if (MouseX >100 && MouseX < 540 && MouseY>250 && MouseY < 300)
		{
			if (mouse_press(100,250,540,300) == 2)//密码框未点击
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightbutton_login(100,250,540,300, LIGHTCYAN, LIGHTGRAY, 1);//标亮函数
					num = 2;
				}
				continue;
			}
			else if (mouse_press(100,250,540,300) == 1)//密码框点击
			{
				MouseS = 0;
				lightbutton_login(100,250,540,300, LIGHTCYAN, LIGHTGRAY, 1);
				u->password[0] = '\0';
				inputpassword(u->password,120,260,10, LIGHTGRAY);
				//输入函数
				if(strlen(u->password) != 0)
					state2 = 1;
				else 
					state2 = 0;
				continue;
			}
		}
		
		if (MouseX >250 && MouseX < 360 && MouseY>310 && MouseY < 330)
		{
			if (mouse_press(250,310,360,330) == 2)//忘记密码未点击
			{
				MouseS = 2;
			}
			else if (mouse_press(250,310,360,330) == 1)//忘记密码点击
			{
				MouseS = 0;
				*pagestate=9;
				return;
				//切换至忘记密码界面
			}
		}
		
		if (MouseX > 110 && MouseX < 260 && MouseY>350 && MouseY < 430)
		{
			if (mouse_press(110,350,260,430) == 2)//登录框未点击
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(110,350,260,430, LIGHTCYAN, LIGHTGRAY, 2);//标亮函数
					num = 3;
				}
				continue;
			}
			else if (mouse_press(110,350,260,430) == 1)//登录框点击
			{
				MouseS = 0;
				if (login_complete(u->userid, u->password))     //信息正确
				{
					if (input_uinfo(u))  //将信息传给u指针
					{
						*pagestate = 8;
						return;
					}
					else
					{
						printf("something wrong");
						delay(3000);
						exit(1);
					}
				}
				else
				{
					continue;
				}
				//检测登录状态函数
			}
		}
		
		if (MouseX > 380 && MouseX < 530 && MouseY>350 && MouseY < 430)
		{
			if (mouse_press(380,350,530,430) == 2)//注册框未点击
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(380,350,530,430, LIGHTCYAN, LIGHTGRAY, 3);//标亮函数
					num = 5;
				}
				continue;
			}
			else if (mouse_press(380,350,530,430) == 1)//注册框点击
			{
				MouseS = 0;
				*pagestate = 7;
				return;
				//切换至用户注册界面
			}
		}

		if (mouse_press(605,5,635,35) == 1)//返回框点击
			{
				MouseS = 0;
				*pagestate = 0;
				delay(500);
				return;
			}
			
		if (num != 0)
		{
			MouseS = 0;
			if (state1 == 0)
			{
				recoverbutton_login(1);//恢复按钮颜色
			}
			if (state2 == 0)
			{
				recoverbutton_login(2);
			}
			if (num == 3 || num == 4 || num == 5 || num == 6)
			{
				recoverbutton_login(num);
			}
			num = 0;
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/**********************************************
FUNCTION:s_1_2_2
DESCRIPTION：管理员登录界面控制
INPUT:pagestate,u
RETURN:无
***********************************************/
void s_1_2_2(int *pagestate)
{
	int num;
	int state = 0;
	char A[15] = { '\0' };	//管理员账号
	char P[10] = { '\0' };	//管理员密码
	int state1 = 0;
	int state2 = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	g_1_2();

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX >100 && MouseX < 540 && MouseY>100 && MouseY < 150)
		{
			if (mouse_press(100,100,540,150) == 2)//管理员框未点击
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)//防止被重复标亮
				{
					lightbutton_login(100,100,540,150, LIGHTCYAN, LIGHTGRAY, 1);//color1为边框色，color2为填充色
					num = 1;
				}
				continue;
				//标亮函数
			}
			else if (mouse_press(100,100,540,150) == 1)//管理员框点击
			{
				MouseS = 0;
				lightbutton_login(100,100,540,150, LIGHTCYAN, LIGHTGRAY, 1);
				A[0] = '\0';
				inputadmin(A, 120,110, 12, DARKGRAY);
				//输入函数
				if(strlen(A) != 0)
					state1 = 1;
				else 
					state1 = 0;
				continue;
			}
		}
		if (MouseX >100 && MouseX < 540 && MouseY>250 && MouseY < 300)
		{
			if (mouse_press(100,250,540,300) == 2)//密码框未点击
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightbutton_login(100,250,540,300, LIGHTCYAN, LIGHTGRAY, 1);//标亮函数
					num = 2;
				}
				continue;
			}
			else if (mouse_press(100,250,540,300) == 1)//密码框点击
			{
				MouseS = 0;
				lightbutton_login(100,250,540,300, LIGHTCYAN, LIGHTGRAY, 1);
				P[0] = '\0';
				inputpassword(P, 120,260, 8, DARKGRAY);
				if(strlen(P) != 0)
					state2 = 1;
				else 
					state2 = 0;
				continue;
				//输入函数
			}
		}
		if (MouseX > 110 && MouseX < 260 && MouseY>350 && MouseY < 430)
		{
			if (mouse_press(110,260,350,430) == 2)//登录框未点击
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(110,260,350,430, WHITE, LIGHTBLUE, 2);//标亮函数
					num = 3;
				}
			continue;
			}
			else if (mouse_press(110,260,350,430) == 1)//登录框点击
			{
				MouseS = 0;
				if (admin_judge(A, P))
				{
					//admin_control();
				}
				else
				{
					continue;
				}
				continue;
				//检查是否与录入数据库的管理员身份相符

			}
		}
		
		if (mouse_press(605,5,635,35) == 1)//返回框点击
			{
				MouseS = 0;
				*pagestate = 1;
				delay(500);
				return;
			}
		}
		if (state != 0)
		{
			MouseS = 0;
			if (state1 == 0)
			{
				recoverbutton_login(1);//恢复按钮颜色
			}
			if (state2 == 0)
			{
				recoverbutton_login(2);
			}
			if (state == 3 || state == 4 || state == 5)
			{
				recoverbutton_login(state);
			}
			state = 0;
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}

/*********************************************
FUNCTION:lightbutton_login
DESCRIPTION：用户登录界面按钮点亮
INPUT:x,y,x1,y1,color1,color2,flag
RETURN:无
***********************************************/
void lightbutton_login(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(100);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框
	switch (flag)
	{
		case 1:
			break;
		case 2:
			puthz(120,360, "登录", 32, 50, WHITE);
			break;
		case 3:
			puthz(390,360, "注册", 32, 50, WHITE);
			break;
		default:
			closegraph();
			printf("something runs wrong in lightbutton");
			exit(1);
	}
}

/*********************************************
FUNCTION:recoverbutton_login
DESCRIPTION：用户登录界面按钮点亮恢复
INPUT:status
RETURN:无
***********************************************/
void recoverbutton_login(int status)
{
	clrmous(MouseX, MouseY);	
	if (status == 1 || status == 2)
	{
		setfillstyle(SOLID_FILL, WHITE);
		setcolor(RED);
		setlinestyle(SOLID_LINE, 0, 3);
	}
	else if (status == 3)
	{
		setfillstyle(SOLID_FILL, RED);
	}
	else
	{
		setfillstyle(SOLID_FILL, WHITE);
		setlinestyle(SOLID_LINE, 0, 1);
		setcolor(LIGHTRED);
	}
	switch (status)
	{
	case 1:
		bar(60,100,540,150);
		rectangle(60,100,540,150);
		puthz(70,120,"账号",32,50,WHITE);
		break;
	case 2:
		bar(60,250,540,300);
		rectangle(60,250,540,300);
		puthz(70,270,"密码",32,50,WHITE);
		break;
	case 3:
		setfillstyle(SOLID_FILL, RED);
		bar(110,350,260,430);
		puthz(150,380,"登陆",48,80,WHITE);
		break;
	case 4:
		setfillstyle(SOLID_FILL, RED);
		bar(380,350,530,430);
		puthz(420,380,"注册",48,80,WHITE);
		break;
	}
}





