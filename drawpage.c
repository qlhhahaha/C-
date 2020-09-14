#include"common.h"
#include"hz.h"
#include"drawfun.h"
#include"drawpage.h"

/*
作用：绘制1主页面
void g_1(void)
调用：无
返回：无
*/
void g_1(void)
{
	setbkcolor(RED);
	setcolor(WHITE);
	rectangle(80,80,560,160);
	puthz(100,100,"物资捐赠与发放系统",48,50,WHITE);
	rectangle(30,300,180,360);
	puthz(55,310,"登陆",32,80,WHITE);
	rectangle(245,300,395,360);
	puthz(255,310,"使用说明",32,35,WHITE);
	rectangle(460,300,610,360);
	puthz(470,310,"关于我们",32,35,WHITE);
	rectangle(605,5,635,35);
	line(610,10,630,30);
	line(630,10,610,30);
}

/*
作用：绘制1.1身份选择页面
void g_1_1(void)
调用：无
返回：无
*/
void g_1_1(void)
{
	cleardevice();
	setbkcolor(RED);
	setcolor(WHITE);
	rectangle(160,60,480,420);
	puthz(240,100,"选择身份",32,50,WHITE);
	rectangle(240,170,400,220);
	puthz(285,180,"个人",32,40,WHITE);
	rectangle(240,260,400,310);
	puthz(285,270,"团体",32,40,WHITE);
	rectangle(240,350,400,400);
	puthz(270,360,"管理员",32,35,WHITE);
	rectangle(605,5,635,35);
	line(610,10,630,30);
	line(630,10,610,30);
}

/*
作用：绘制0.1使用说明页面
void g_0_1(void)
调用：无
返回：无
*/
void g_0_1(void)
{
	
}

/*
作用：绘制0.2关于我们页面
void g_0_2(void)
调用：无
返回：无
*/
void g_0_2(void)
{
	
}

/*
作用：绘制1.2登陆页面
void g_1_2(void)
调用：无
返回：无
*/
void g_1_2(void)
{
	cleardevice();
	setbkcolor(LIGHTBLUE);
	setcolor(BLACK);
	
	FrameSha(60,100,540,150,WHITE,DARKGRAY,3);
	LineThick(130,100,130,150,WHITE,3,2);
	puthz(65,120,"账号",32,40,WHITE);
	
	FrameSha(60,250,540,300,WHITE,DARKGRAY,3);
	LineThick(130,250,130,300,WHITE,3,2);
	puthz(65,270,"密码",32,40,WHITE);
	
	Linex(250,330,360,330,WHITE);
	puthz(260,315,"忘记密码？",16,20,WHITE);
	
	Barshadow(110,350,260,430,LIGHTCYAN,LIGHTGRAY);
	puthz(130,360,"登陆",32,80,WHITE);
	
	Barshadow(380,350,530,430,LIGHTCYAN,LIGHTGRAY);
	puthz(400,360,"注册",32,80,WHITE);
	
	rectangle(605,5,635,35);
	line(610,10,630,30);
	line(630,10,610,30);
}

/*
作用：绘制1.3注册页面
void g_1_3(void)
调用：无
返回：无
*/
void g_1_3(void)
{
	//画登陆小人
	setcolor(LIGHTBLUE);
	setfillstyle(1, LIGHTBLUE);
	fillellipse(320, 40, 25, 25);//椭圆填充函数，x，y为圆心，x1，y1为x轴半径与y轴半径
	setfillstyle(1, WHITE);
	pieslice(320, 40, 230, 310, 25);//扇形函数，x，y为圆心，stangle与endangle为角度范围（角度制），radius为半径
	fillellipse(320, 40 - 5, 12, 12);
	setcolor(WHITE);
	circle(320, 40 - 5, 12);		

	setbkcolor(CYAN);
	setcolor(BLUE);
	FrameSha(60,80,540,120,LIGHTMAGENTA,BROWN,3);
	LineThick(160,80,160,120,LIGHTMAGENTA,3,2);
	puthz(65,90,"账号",24,50,BLACK);

	FrameSha(60,140,540,180,LIGHTMAGENTA,BROWN,3);
	LineThick(160,140,160,180,LIGHTMAGENTA,3,2);
	puthz(65,150,"密码",32,50,BLACK);

	FrameSha(60,200,540,240,LIGHTMAGENTA,BROWN,3);
	LineThick(160,200,160,240,LIGHTMAGENTA,3,2);
	puthz(65,210,"确认",32,50,BLACK);

	FrameSha(60,260,540,300,LIGHTMAGENTA,BROWN,3);
	LineThick(160,260,160,300,LIGHTMAGENTA,3,2);
	puthz(65,270,"验证",32,50,BLACK);
	
	Barshadow(250,390,410,450,LIGHTMAGENTA,BROWN);
	puthz(270,400,"注册",48,50,BLACK);

	rectangle(605,5,635,35);
	line(610,10,630,30);
	line(630,10,610,30);
}

/*
作用：绘制1.4忘记密码页面
void g_1_4(void)
调用：无
返回：无
*/
void g_1_4(void)
{
	setbkcolor(CYAN);
	setcolor(BLUE);
	FrameSha(60,80,540,120,LIGHTMAGENTA,BROWN,3);
	LineThick(160,80,160,120,LIGHTMAGENTA,3,2);
	puthz(65,90,"账号",24,50,BLACK);

	FrameSha(60,160,540,200,LIGHTMAGENTA,BROWN,3);
	LineThick(160,160,160,200,LIGHTMAGENTA,3,2);
	puthz(65,170,"电话",32,50,BLACK);

	FrameSha(60,240,540,280,LIGHTMAGENTA,BROWN,3);
	LineThick(160,240,160,280,LIGHTMAGENTA,3,2);
	puthz(65,250,"密码",32,50,BLACK);

	FrameSha(60,320,540,360,LIGHTMAGENTA,BROWN,3);
	LineThick(160,320,160,360,LIGHTMAGENTA,3,2);
	puthz(65,330,"确认",32,50,BLACK);
	
	Barshadow(250,390,410,450,LIGHTMAGENTA,BROWN);
	puthz(270,400,"修改",48,50,BLACK);

	rectangle(605,5,635,35);
	line(610,10,630,30);
	line(630,10,610,30);
}

void g_2_0(void)//绘制上方常驻菜单栏
{
	setbkcolor(RED);
	setcolor(BLUE);
	rectangle(0,0,639,479);
	line(0,20,639,20);
	line(80,0,80,20);
	line(160,0,160,20);
	line(240,0,240,20);
	line(320,0,320,20);
	line(400,0,400,20);
	line(560,0,560,20);
	puthz(4,2,"爱心背景",16,19,WHITE);
	puthz(84,2,"我要捐助",16,19,WHITE);
	puthz(164,2,"发起请求",16,19,WHITE);
	puthz(244,2,"捐助查询",16,19,WHITE);
	puthz(324,2,"爱心留言",16,19,WHITE);
	puthz(404,2,"互助商城",16,19,WHITE);
	puthz(484,2,"个人信息",16,19,WHITE);
	puthz(570,2,"退出",16,29,WHITE);
}

void g_2_0_0(void)//绘制右方常驻菜单栏
{
	setcolor(BLUE);
	rectangle(604,20,639,479);
	puthz(606,26,"上",24,24,WHITE);
	puthz(606,56,"一",24,24,WHITE);
	puthz(606,86,"页",24,24,WHITE);
	line(604,116,639,116);
	puthz(606,122,"时",24,24,WHITE);
	puthz(606,152,"间",24,24,WHITE);
	puthz(606,212,"序",24,24,WHITE);
	line(604,240,639,240);
	puthz(606,246,"种",24,24,WHITE);
	puthz(606,276,"类",24,24,WHITE);
	puthz(606,306,"筛",24,24,WHITE);
	puthz(606,336,"选",24,24,WHITE);
	line(604,366,639,366);
	puthz(606,372,"下",24,24,WHITE);
	puthz(606,402,"一",24,24,WHITE);
	puthz(606,432,"页",24,24,WHITE);
}

void g_2_1(void)//绘制爱心背景页面
{
	
}

void g_2_2_0(void)//绘制表格线
{
	int i=0;
	setcolor(BLUE);
	rectangle(0,20,639,479);
	line(0,68,604,68);
	for(i=0;i<9;i++)
	{
		line(0,109+41*i,604,109+41*i);
	}
	line(421,68,421,479);
	line(495,68,495,479);
	
}

void g_2_4_0(void)//绘制选择查询方式的弹窗
{
	setviewport(139,140,455,360,1);
	setbkcolor(DARKGRAY);
	setcolor(YELLOW);
	rectangle(139,140,455,360);
	rectangle(223,180,381,240);
	puthz(230,195,"所有捐助",32,38,BLACK);
	rectangle(223,260,381,320);
	puthz(230,275,"我的捐助",32,38,BLACK);
	rectangle(430,140,455,165);
	line(435,145,250,160);
	line(435,160,250,145);
}

void g_2_8(void)//绘制确认是否退出的弹窗
{
	setviewport(139,140,455,360,1);
	setbkcolor(DARKGRAY);
	setcolor(YELLOW);
	rectangle(139,140,455,360);
	rectangle(223,180,381,240);
	puthz(230,195,"退出",32,90,BLACK);
	rectangle(223,260,381,320);
	puthz(230,275,"取消",32,90,BLACK);
}