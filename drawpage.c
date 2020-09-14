#include"common.h"
#include"hz.h"
#include"drawfun.h"
#include"drawpage.h"

/*
���ã�����1��ҳ��
void g_1(void)
���ã���
���أ���
*/
void g_1(void)
{
	setbkcolor(RED);
	setcolor(WHITE);
	rectangle(80,80,560,160);
	puthz(100,100,"���ʾ����뷢��ϵͳ",48,50,WHITE);
	rectangle(30,300,180,360);
	puthz(55,310,"��½",32,80,WHITE);
	rectangle(245,300,395,360);
	puthz(255,310,"ʹ��˵��",32,35,WHITE);
	rectangle(460,300,610,360);
	puthz(470,310,"��������",32,35,WHITE);
	rectangle(605,5,635,35);
	line(610,10,630,30);
	line(630,10,610,30);
}

/*
���ã�����1.1���ѡ��ҳ��
void g_1_1(void)
���ã���
���أ���
*/
void g_1_1(void)
{
	cleardevice();
	setbkcolor(RED);
	setcolor(WHITE);
	rectangle(160,60,480,420);
	puthz(240,100,"ѡ�����",32,50,WHITE);
	rectangle(240,170,400,220);
	puthz(285,180,"����",32,40,WHITE);
	rectangle(240,260,400,310);
	puthz(285,270,"����",32,40,WHITE);
	rectangle(240,350,400,400);
	puthz(270,360,"����Ա",32,35,WHITE);
	rectangle(605,5,635,35);
	line(610,10,630,30);
	line(630,10,610,30);
}

/*
���ã�����0.1ʹ��˵��ҳ��
void g_0_1(void)
���ã���
���أ���
*/
void g_0_1(void)
{
	
}

/*
���ã�����0.2��������ҳ��
void g_0_2(void)
���ã���
���أ���
*/
void g_0_2(void)
{
	
}

/*
���ã�����1.2��½ҳ��
void g_1_2(void)
���ã���
���أ���
*/
void g_1_2(void)
{
	cleardevice();
	setbkcolor(LIGHTBLUE);
	setcolor(BLACK);
	
	FrameSha(60,100,540,150,WHITE,DARKGRAY,3);
	LineThick(130,100,130,150,WHITE,3,2);
	puthz(65,120,"�˺�",32,40,WHITE);
	
	FrameSha(60,250,540,300,WHITE,DARKGRAY,3);
	LineThick(130,250,130,300,WHITE,3,2);
	puthz(65,270,"����",32,40,WHITE);
	
	Linex(250,330,360,330,WHITE);
	puthz(260,315,"�������룿",16,20,WHITE);
	
	Barshadow(110,350,260,430,LIGHTCYAN,LIGHTGRAY);
	puthz(130,360,"��½",32,80,WHITE);
	
	Barshadow(380,350,530,430,LIGHTCYAN,LIGHTGRAY);
	puthz(400,360,"ע��",32,80,WHITE);
	
	rectangle(605,5,635,35);
	line(610,10,630,30);
	line(630,10,610,30);
}

/*
���ã�����1.3ע��ҳ��
void g_1_3(void)
���ã���
���أ���
*/
void g_1_3(void)
{
	//����½С��
	setcolor(LIGHTBLUE);
	setfillstyle(1, LIGHTBLUE);
	fillellipse(320, 40, 25, 25);//��Բ��亯����x��yΪԲ�ģ�x1��y1Ϊx��뾶��y��뾶
	setfillstyle(1, WHITE);
	pieslice(320, 40, 230, 310, 25);//���κ�����x��yΪԲ�ģ�stangle��endangleΪ�Ƕȷ�Χ���Ƕ��ƣ���radiusΪ�뾶
	fillellipse(320, 40 - 5, 12, 12);
	setcolor(WHITE);
	circle(320, 40 - 5, 12);		

	setbkcolor(CYAN);
	setcolor(BLUE);
	FrameSha(60,80,540,120,LIGHTMAGENTA,BROWN,3);
	LineThick(160,80,160,120,LIGHTMAGENTA,3,2);
	puthz(65,90,"�˺�",24,50,BLACK);

	FrameSha(60,140,540,180,LIGHTMAGENTA,BROWN,3);
	LineThick(160,140,160,180,LIGHTMAGENTA,3,2);
	puthz(65,150,"����",32,50,BLACK);

	FrameSha(60,200,540,240,LIGHTMAGENTA,BROWN,3);
	LineThick(160,200,160,240,LIGHTMAGENTA,3,2);
	puthz(65,210,"ȷ��",32,50,BLACK);

	FrameSha(60,260,540,300,LIGHTMAGENTA,BROWN,3);
	LineThick(160,260,160,300,LIGHTMAGENTA,3,2);
	puthz(65,270,"��֤",32,50,BLACK);
	
	Barshadow(250,390,410,450,LIGHTMAGENTA,BROWN);
	puthz(270,400,"ע��",48,50,BLACK);

	rectangle(605,5,635,35);
	line(610,10,630,30);
	line(630,10,610,30);
}

/*
���ã�����1.4��������ҳ��
void g_1_4(void)
���ã���
���أ���
*/
void g_1_4(void)
{
	setbkcolor(CYAN);
	setcolor(BLUE);
	FrameSha(60,80,540,120,LIGHTMAGENTA,BROWN,3);
	LineThick(160,80,160,120,LIGHTMAGENTA,3,2);
	puthz(65,90,"�˺�",24,50,BLACK);

	FrameSha(60,160,540,200,LIGHTMAGENTA,BROWN,3);
	LineThick(160,160,160,200,LIGHTMAGENTA,3,2);
	puthz(65,170,"�绰",32,50,BLACK);

	FrameSha(60,240,540,280,LIGHTMAGENTA,BROWN,3);
	LineThick(160,240,160,280,LIGHTMAGENTA,3,2);
	puthz(65,250,"����",32,50,BLACK);

	FrameSha(60,320,540,360,LIGHTMAGENTA,BROWN,3);
	LineThick(160,320,160,360,LIGHTMAGENTA,3,2);
	puthz(65,330,"ȷ��",32,50,BLACK);
	
	Barshadow(250,390,410,450,LIGHTMAGENTA,BROWN);
	puthz(270,400,"�޸�",48,50,BLACK);

	rectangle(605,5,635,35);
	line(610,10,630,30);
	line(630,10,610,30);
}

void g_2_0(void)//�����Ϸ���פ�˵���
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
	puthz(4,2,"���ı���",16,19,WHITE);
	puthz(84,2,"��Ҫ����",16,19,WHITE);
	puthz(164,2,"��������",16,19,WHITE);
	puthz(244,2,"������ѯ",16,19,WHITE);
	puthz(324,2,"��������",16,19,WHITE);
	puthz(404,2,"�����̳�",16,19,WHITE);
	puthz(484,2,"������Ϣ",16,19,WHITE);
	puthz(570,2,"�˳�",16,29,WHITE);
}

void g_2_0_0(void)//�����ҷ���פ�˵���
{
	setcolor(BLUE);
	rectangle(604,20,639,479);
	puthz(606,26,"��",24,24,WHITE);
	puthz(606,56,"һ",24,24,WHITE);
	puthz(606,86,"ҳ",24,24,WHITE);
	line(604,116,639,116);
	puthz(606,122,"ʱ",24,24,WHITE);
	puthz(606,152,"��",24,24,WHITE);
	puthz(606,212,"��",24,24,WHITE);
	line(604,240,639,240);
	puthz(606,246,"��",24,24,WHITE);
	puthz(606,276,"��",24,24,WHITE);
	puthz(606,306,"ɸ",24,24,WHITE);
	puthz(606,336,"ѡ",24,24,WHITE);
	line(604,366,639,366);
	puthz(606,372,"��",24,24,WHITE);
	puthz(606,402,"һ",24,24,WHITE);
	puthz(606,432,"ҳ",24,24,WHITE);
}

void g_2_1(void)//���ư��ı���ҳ��
{
	
}

void g_2_2_0(void)//���Ʊ����
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

void g_2_4_0(void)//����ѡ���ѯ��ʽ�ĵ���
{
	setviewport(139,140,455,360,1);
	setbkcolor(DARKGRAY);
	setcolor(YELLOW);
	rectangle(139,140,455,360);
	rectangle(223,180,381,240);
	puthz(230,195,"���о���",32,38,BLACK);
	rectangle(223,260,381,320);
	puthz(230,275,"�ҵľ���",32,38,BLACK);
	rectangle(430,140,455,165);
	line(435,145,250,160);
	line(435,160,250,145);
}

void g_2_8(void)//����ȷ���Ƿ��˳��ĵ���
{
	setviewport(139,140,455,360,1);
	setbkcolor(DARKGRAY);
	setcolor(YELLOW);
	rectangle(139,140,455,360);
	rectangle(223,180,381,240);
	puthz(230,195,"�˳�",32,90,BLACK);
	rectangle(223,260,381,320);
	puthz(230,275,"ȡ��",32,90,BLACK);
}