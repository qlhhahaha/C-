#include"loginfun.h"
#include"common.h"
#include"hz.h"
#include"database.h"
#include"register.h"

/*********************************************
FUNCTION:admin_judge
DESCRIPTION：管理员身份是否匹配
INPUT:admin,pass
RETURN:无
***********************************************/
int admin_judge(char* admin, char* pass)
{
	if (strlen(admin) == 0)
	{
		puthz(550,120, "未输入", 16, 17, RED);
	}
	if (strlen(pass) == 0)
	{
		puthz(550,260, "未输入", 16, 17, RED);
		return 0;
	}
	if ((strcmp(admin, "qlh") == 0
		|| strcmp(admin, "lhy") == 0)
		&&strcmp(pass, "aia1905") == 0)
	{
		puthz(300,440, "登录成功", 16, 20, RED);
		return 1;
	}
	else
	{
		puthz(550,120, "管理员信息有误", 16, 20, RED);
		return 0;
	}
	return 0;
}

/*********************************************
FUNCTION:register_complete
DESCRIPTION：用来判断注册信息是否输入完全和正确
INPUT:u,p,cp,vc,rdvc
RETURN:1/0
***********************************************/
int register_complete(char*u,char *p,char* cp, char* vc,char* rdvc)//rdvc为randomvc
{
	int i;
	int state = 0;//是否输入的变量
	int state1 = 1;//确认密码是否一致的变量
	int state2 = 1;//验证码是否一致的变量
	while (1)
	{
		recoverhz(547, 200, BLACK);
		recoverhz(130, 53, BLACK);
		recoverhz(280, 420, BLACK);
		judge(cp, &state, 547, 210);
		judge(vc, &state, 547, 330);
		if (state == 1)
		{
			break;
		}
		else if (state == 0)
		{
			if (!judge_sameuser(u,1))          //  重名则返回0，未重名返回1
			{
				state1 = checkright_confirmedpassword(p, cp, 547, 210);
				state2= checkright_verificationcode(rdvc, vc, 547, 330);
				break;
			}
			else if(judge_sameuser(u,2))//用户名没有重名
			{
				puthz(135, 60, "可用的用户名", 16, 17, RED);
				state1 = checkright_confirmedpassword(p, cp, 547, 210);
				state2 = checkright_verificationcode(rdvc, vc, 547, 330);
				if (state1 != 0 || state2 != 0)
				{
					break;
				}
				else if (state1 == 0 && state2 == 0 )
				{
					input_database(u, p);
					//写入数据库
					puthz(280,420, "注册成功", 16, 17, RED);
					delay(2000);
					return 1;//返回
				}
			}
		}
	}
	return 0;
}


/*********************************************
FUNCTION:input_database
DESCRIPTION：把用户注册信息写入文件
INPUT:name,code
RETURN:1/0
***********************************************/
void input_database(char* name, char* code)
{
	FILE* fp;
	USER* u;
	char n;
	if ((fp = fopen("DATABASE\\USER.dat", "rb+" )) == NULL)//建立数据库
	{
		printf("cannot open file USER.dat");
		delay(3000);
		exit(1);
	}
	if ((u = (USER*)malloc(sizeof(USER))) == NULL)
	{
		printf("memoryallocation runs wrong in loginfun.c");
		delay(3000);
		exit(1);
	}
	memset(u,'\0',sizeof(USER));
	strcpy(u->userid, name);
	strcpy(u->password, code);
	fseek(fp, 0, SEEK_END);//跳转至文件末尾
	fwrite(u, sizeof(USER), 1, fp);//把用户信息写入文件
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close DATABASE.");
		delay(3000);
		exit(1);
	}
}

/*********************************************
FUNCTION:judge_sameuser
DESCRIPTION：判断账户是否出现重名,
	flag为1判断是否注册，
	flag为2判断找回密码中是否存在
INPUT:new_user,flag
RETURN:1/0
***********************************************/
int judge_sameuser(char* new_user,int flag)
{
	int len;
	int i;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen("DATABASE\\USER.dat", "rb+")) == NULL)//建立数据库
	{
		printf("cannot open file USER.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(u->userid, new_user) == 0)
		{
			switch (flag)
			{
			case 1: 
				puthz(135, 60, "用户已被注册", 16, 17, RED);
				break;
			case 2:
				puthz(450, 110, "账号存在", 16, 17, RED);
				break;
			default:
				printf("something wrong");
				delay(3000);
				exit(1);
			}
			if (u != NULL)
			{
				free(u);
				u = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("\n cannot close DATABASE.");
				delay(3000);
				exit(1);
			}
			return 0;
		}
		free(u);
		u = NULL;
	}
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close DATABASE.");
		delay(3000);
		exit(1);
	}
	return 1;
}

/*********************************************
FUNCTION:checkright_password
DESCRIPTION：检查确认密码是否一致
INPUT:str1,str2,x,y
RETURN:1/0
***********************************************/
int checkright_confirmedpassword(char* str1, char* str2, int x, int y)
{
	if (strcmp(str1, str2) != 0)
	{
		puthz(x, y, "两次不一致", 16, 17, RED);
		return 1;
	}
	else if (strcmp(str1, str2) == 0)
	{
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

/*********************************************
FUNCTION:checkright_verificationcode
DESCRIPTION：检查验证码是否一致
INPUT:str1,str2,x,y
RETURN:1/0
***********************************************/
int checkright_verificationcode(char* str1, char* str2,int x,int y)
{
/*	char* cstr1 = NULL,*cstr2 = NULL;
	cstr1 = str1;
	cstr2 = str2;
	while(*cstr1 != '\0')
	{
		if(*cstr1 >= 'a' && *cstr1 <= 'z' || *cstr1 >= 'A' && *cstr1 <= 'Z')
		{   //大小写字符
			if(*cstr2 >= 'a' && *cstr2 <= 'z')     //'A'<'a'
			{
				if(*cstr1 == *cstr2 || *cstr1 == *cstr2 - 32)
				{
					cstr1++;
					cstr2++;
				}  //如果一致
				else
				{
					puthz(x, y, "验证码错误", 16, 17, RED);
					return 1;
				}
			}
			else if(*cstr2 >= 'A' && *cstr2 <= 'Z')
			{
				if(*cstr1 == *cstr2 || *cstr1 == *cstr2 + 32)
				{
					cstr1++;
					cstr2++;
				}
				else
				{
					puthz(x, y, "验证码错误", 16, 17, RED);
					return 1;
				}
			}
		}
		else //验证码不是字母
		{
			if(*cstr1 == *cstr2)
			{
				cstr1++;
				cstr2++;
			}
			else
			{
				puthz(x, y, "验证码错误", 16, 17, RED);
				return 1;
			}	
		}
	}
	if(*cstr2 != '\0')
	{
		puthz(x, y, "验证码错误", 16, 17, RED);
		return 1;
	}
	setcolor(BLUE);
	setlinestyle(SOLID_LINE, 0, 3);
	line(x + 3, y + 8, x + 13, y + 18);
	line(x + 13, y + 18, x + 23, y - 2);
	return 0;
*/
	if (strcmp(str1, str2) != 0)
	{
		puthz(x, y, "验证码错误", 16, 17, RED);
		return 1;
	}
	else if (strcmp(str1, str2) == 0)
	{
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

/*********************************************
FUNCTION:inputadmin
DESCRIPTION：输入账号、身份证号等无需隐藏的信息
INPUT:id,x1,y1,charnum,color
RETURN:无
***********************************************/
void inputadmin(char* id, int x1, int y1, int charnum, int color)//输入的字符串，输入的xy，输入的字符限制，输入框的颜色
{
	int i = 0;//i用于计数
	char t;
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);//设置水平方向和垂直方向的文本排齐方式
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);//画光标线
	while (1)
	{
		t = bioskey(0); //用t记录键值
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//当t不为特殊键时
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //遮盖光标
					outtextxy(x1 + 8 + i * 18, y1-1, id + i);//输出t字符(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//遮盖光标  
				break;
			}
		}
	}
}

/*********************************************
FUNCTION:inputpassword
DESCRIPTION：函数功能：输入密码等需要隐藏的信息
INPUT:id,x1,y1,charnum,color
RETURN:无
***********************************************/
void inputpassword(char* id, int x1, int y1, int charnum, int color)
{
	int i = 0;
	char t;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	while (1)
	{
		t = bioskey(0);//读取键值
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//033表示Esc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
					outtextxy(x1 + 8 + i * 18, y1 + 4, "*");//输出*字符
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
				break;
			}
		}
	}
}

/*********************************************
FUNCTION:judge
DESCRIPTION：判断注册的状态
INPUT:str,p,x,y
RETURN:无
***********************************************/
void judge(char* str, int* p, int x, int y)
{
	if (strlen(str) == 0)
	{
		*p = 1;
		puthz(x, y, "未输入", 16, 17, RED);
	}
	else
	{
		*p = 0;
	}
}

/*********************************************
FUNCTION:recoverhz
DESCRIPTION：用于覆盖汉字
INPUT:x,y,color
RETURN:无
***********************************************/
void recoverhz(int x, int y,int color)
{
	setfillstyle(SOLID_FILL,color);
	bar(x, y, x + 100, y + 30);
}

/*********************************************
FUNCTION:login_complete
DESCRIPTION：用来判断登录信息是否输入完全和正确
INPUT:u,p
RETURN:1/0
***********************************************/
int login_complete(char* u, char* p)
{
	int state1 = 1;//是否输入的变量
	int state2 = 1;
	while (1)
	{
		recoverhz(100, 100, BLACK);
		recoverhz(100, 250, BLACK);
		judge(u, &state1, 550, 120);
		judge(p, &state2, 550, 270);
		if (state1 == 1 || state2 == 1)
		{
			break;
		}
		else if (state1 == 0 && state2 == 0)
		{
			if (judge_rightpassword(u, p))
			{
				return 1;
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}

/*********************************************
FUNCTION:judge_rightpassword
DESCRIPTION：判断用户名和密码是否匹配
	匹配则登录
INPUT:name,id,pass,againpass
RETURN:1/0
***********************************************/
int judge_rightpassword(char* name, char* pass)	
{
	int len;
	int i;
	FILE* fp;
	USER* u;
	if ((fp = fopen("DATABASE\\USER.dat", "rb+")) == NULL)
	{
		printf("cannot open file USER.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);//计算出USER结构体的个数，即已注册用户的个数
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in loginfun.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(name, u->userid) == 0)//用户名匹配
		{
			if (strcmp(pass, u->password) != 0)//密码不配
			{
				puthz(550,260, "密码错误", 16, 17, RED);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				break;
			}
			else if (strcmp(pass, u->password) == 0)//密码匹配
			{
				puthz(300,440, "登录成功", 16, 17, RED);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				delay(1000);
				if (fclose(fp) != 0)
				{
					printf("\n cannot close DATABASE");
					delay(3000);
					exit(1);
				}
				return 1;
				//切换界面
			}
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (i == len)
	{
		puthz(550,110, "账户未注册", 16, 17, RED);//走到最后一位
	}

	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close DATABASE");
		delay(3000);
		exit(1);
	}
	return 0;
}

/*********************************************
FUNCTION:input_uinfo
DESCRIPTION：函数功能：输入用户信息
INPUT:us
RETURN:无
***********************************************/
int input_uinfo(USER* us)
{
	int i;
	int len;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen("DATABASE\\USER.dat", "rb+" )) == NULL)
	{
		printf("cannot open file USER.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//文件指针定位到最后一位
	len = ftell(fp) / sizeof(USER);//计算用户个数
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in loginfun.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);//每次往后移一个用户
		fread(u, sizeof(USER), 1, fp);		  //将信息读入u
		if (strcmp(us->userid, u->userid) == 0)
		{
			memset(us,'\0',sizeof(USER));              //先重置
			strcpy(us->userid,u->userid); 
			strcpy(us->password,u->password); 
			if (u != NULL)
			{
				free(u);
				u = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("\n cannot close DATABASE");
				exit(1);
			}
			delay(2000);
			return 1;
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close DATABASE");
		exit(1);
	}
	return 0;
}

/*********************************************
FUNCTION:id_phone
DESCRIPTION：判断账号与电话号是否匹配，
	并判断两次输入的密码是否相同，
	若匹配且相同则写入新密码。
INPUT:id,ph,pass,againpass
RETURN:1/0
***********************************************/
int id_phone(char* id, char* ph, char* np, char* cp)
{
	int str;
	int len;//用于计算用户个数
	int i,j;//用于计数
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen("database\\USER.dat", "rb+" )) == NULL)
	{
		printf("cannot open file USER.dat");
		delay(2000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//文件指针定位到最后一位
	len = ftell(fp) / sizeof(USER);//计算用户个数
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in loginfun.c");
			delay(2000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);//每次往后移一个用户
		fread(u, sizeof(USER), 1, fp);//将信息读入u
		if (strcmp(id, u->userid) == 0)
		{
			if (strcmp(ph, u->phone) != 0)
			{
				puthz(540,165, "电话不匹配", 16, 20, RED);
				break;
			}
			else if (strcmp(ph, u->phone) == 0)
			{
				if (strcmp(np, cp) == 0)//两次输入密码相同
				{
					u->password[0] = '\0';
					strcpy(u->password, np);
					fseek(fp, i * sizeof(USER), SEEK_SET);
					fwrite(u, sizeof(USER), 1, fp);//修改完后一定要记得写入数据
					puthz(420,415,"修改成功",16,20,RED);
					if (u != NULL)
					{
						free(u);
						u = NULL;
					}
					if (fclose(fp) != 0)
					{
						printf("\n cannot close Database");
						exit(1);
					}
					delay(2000);
					return 1;
				}
			}
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}

	}

	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database");
		exit(1);
	}
	return 0;
}