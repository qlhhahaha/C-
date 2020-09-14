#ifndef _DATA_H_
#define _DATA_H_

typedef struct userinfo
{
	char userid[15];    //不超过11位，个人用户名
	char password[15];  //不超过10位，密码
	char phone[11];		//不超过11位，手机号
	long int score;
	int times;
	int achi;
	int usercode;
	int goods[9];
}USER;	//封装用户信息

typedef struct admininfo
{
	char userid[15];//不超过11位，管理员账号
	char password[10];//不超过10位，管理员密码
}ADMIN;//封装管理员信息

typedef struct projectinfo
{
	char proname[30];
	char place[40];
	int protype;
	char call[12];
	char manname[8];
	char userid[15];
	int procode;
	long int amount[2][9];
	char descri[200];
	int state;
}PRO;//封装项目信息

typedef struct reinfo
{
	int procode;
	char userid[15];
	long int amount[9];
}RECORD;//封装捐赠记录信息

typedef struct messinfo
{
	char userid[15];
	char text[100];
}MESSAGE;//封装留言信息
#endif