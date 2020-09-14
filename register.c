#include"common.h"
#include"register.h"
#include"hz.h"

void s_1_3(int *pagestate)
{
	int num = 0;
	char str[6] = { '\0' };
	char U[15] = { '\0' };//�û���
	char P[20] = { '\0' };//����
	char CP[20] = { '\0' };//ȷ������
	char VC[6] = { '\0' };//5λ����֤��
	int state1 = 0;       //���������жϲ���
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	int state5 = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	g_1_3();
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 160 && MouseX < 540 && MouseY>80 && MouseY < 120)
		{
			if (mouse_press(160,80,540,120) == 2)//δ����˺ſ�
			{
				MouseS = 2;
				if (num == 0 && state1 == 0) //num = 0��ֹ�ظ�����
				{
					lightbutton_register(160,80,540,120, LIGHTCYAN, LIGHTGRAY, 0);
					num = 1;
				}
				continue;
			}

			else if (mouse_press(160,80,540,120) == 1)      //����˺ſ�
			{
				MouseS = 0;
				lightbutton_register(160,80,540,120, LIGHTCYAN, LIGHTGRAY, 0);
				U[0] = '\0';
				inputadmin(U,170,85,11,LIGHTGRAY);//������ַ����������xy��������ַ����ƣ���������ɫ
				if(strlen(U) != 0)
					state1 = 1;
				else
					state1 = 0;
				continue;
			}
		}
		if (MouseX > 160 && MouseX < 540 && MouseY>140 && MouseY < 180)
		{
			if (mouse_press(160,140,540,180) == 2)//δ��������
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightbutton_register(160,140,540,180, LIGHTCYAN, LIGHTGRAY, 0);
					num = 2;
				}
				continue;
			}

			else if (mouse_press(160,140,540,180) == 1)     //��������
			{
				lightbutton_register(160,140,540,180, LIGHTCYAN, LIGHTGRAY, 0);
				MouseS = 0;
				P[0] = '\0';
				inputpassword(P, 170, 145, 10, LIGHTGRAY);//���뺯��
				if(strlen(P) != 0)
					state2 = 1;
				else
					state2 = 0;
				continue;
			}
		}

		if (MouseX > 160 && MouseX < 540 && MouseY>200 && MouseY < 240)
		{
			if (mouse_press(160,200,540,240) == 2)     //δ���ȷ�������
			{
				MouseS = 2;
				if (num == 0 && state3 == 0)
				{
					lightbutton_register(160,200,540,240, LIGHTCYAN, LIGHTGRAY, 0);
					num = 3;
				}
				continue;
			}

			else if (mouse_press(160,200,540,240) == 1)      //���ȷ�������
			{
				lightbutton_register(160,200,540,240, LIGHTCYAN, LIGHTGRAY, 0);
				MouseS = 0;
				CP[0] ='\0';
				inputpassword(CP, 170, 205, 10, LIGHTGRAY);
				//���뺯��
				if(strlen(CP) != 0)
					state3 = 1;
				else
					state3 = 0;
				continue;
			}
		}

		if (mouse_press(60,260,160,300) == 1)//���������֤��
		{
			clrmous(MouseX, MouseY);
			delay(100);
			setfillstyle(1, WHITE);
			bar(60,260,160,300);
			random_str(str);//��str[]������һ�������λ��
			setcolor(BLUE);
			settextjustify(LEFT_TEXT, TOP_TEXT);
			settextstyle(1, HORIZ_DIR, 3);
			outtextxy(65,270, str);//��(x,y)����ʾ�ַ���
			continue;
		}

		if (MouseX > 160 && MouseX < 540 && MouseY>260 && MouseY < 300)
		{
			MouseS = 2;
			if (mouse_press(160,260,540,300) == 2)            //δ�����֤�������
			{
				if (num == 0 && state4 == 0)
				{
					lightbutton_register(160,260,540,300,LIGHTCYAN, LIGHTGRAY, 0);
					num = 4;
				}
				continue;
			}

			else if (mouse_press(160,260,540,300) == 1)
			{
				lightbutton_register(160,260,540,300, LIGHTCYAN, LIGHTGRAY, 0);
				MouseS = 0;
				VC[0] = '\0';
				inputadmin(VC, 170, 265, 5, LIGHTGRAY);
				//���뺯��
				if(strlen(VC) != 0)
					state4 = 1;
				else 
					state4 = 0;
				continue;
			}
		}

		if (MouseX > 250 && MouseX < 410 && MouseY>350 && MouseY < 410)
		{
			if (mouse_press(250,350,410,410) == 2)					//δ���ע���
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_register(250,350,410,410, LIGHTCYAN, LIGHTGRAY, 1);
					num = 5;
				}
				continue;
			}

			else if (mouse_press(250,350,410,410) == 1)
			{
				MouseS = 0;
				if (register_complete(U, P, CP, VC, str))
				{
					*pagestate = 5;
					return;
				}
				else
				{
					continue;
				}
				//ע���ж�
			}
		}

		if (mouse_press(605,5,635,35) == 1)
		{
			*pagestate = 5;//������ؿ����½����½ҳ��
			delay(500);
			return;
		}

		if (num != 0)
		{
			MouseS = 0;
			if (state1 == 0)
			{
				recoverbutton_register(1);
			}
			if (state2 == 0)
			{
				recoverbutton_register(2);
			}
			if (state3 == 0)
			{
				recoverbutton_register(3);
			}
			if (state4 == 0)
			{
				recoverbutton_register(4);
			}
			if (num == 5)
			{
				recoverbutton_register(5);
			}
			num = 0;
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/******************************************
FUNCTION: lightbutton_register
DESCRIPTION: ע��������
INPUT: x,y,x1,y1,color1,color2,flag
RETURN: ��
******************************************/
void lightbutton_register(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//���߿�

	if (flag == 1)
	{
		puthz(270,360, "ע��", 48, 50, LIGHTRED);
	}
}
/****************************************
FUNCTION: random_str
DESCRIPTION: �����֤��
INPUT: str
RETURN: �� 
****************************************/
void random_str(char* str)
{
	char a, j, i;//i���ڼ�����j�������ж�������aΪĳһλ���ֵ
	srand(time(NULL));
	for (i = 0; i < 5; i++)
	{
		j = rand() % 3;//jΪ0��1��2
		if (j == 0)
		{
			a = rand() % 12 + 77;
			str[i] = a;
		}
		else if (j == 1)
		{
			a = rand() % 11 + 66;
			str[i] = a;
		}
		else
		{
			a = rand() % 10 + 55;
			str[i] = a;
		}
	}
	str[5] = '\0';
}

/**********************************************
FUNCTION: recoverbutton_register
DESCRIPTION: ע�����ָ�����
INPUT:	status
RETURN: ��
**********************************************/
void recoverbutton_register(int status)
{
	clrmous(MouseX, MouseY);
	setfillstyle(1, WHITE);
	switch (status)
	{
		case 1:
			bar(160,80,540,120);
			break;
			
		case 2:
			bar(160,140,540,180);
			break;
			
		case 3:
			bar(160,200,540,240);
			break;
			
		case 4:
			bar(160,260,540,300);
			break;
			
		case 5:
			setfillstyle(1, BLUE);
			bar(250,350,410,410);
			puthz(270,360, "ע��", 48, 50, BLACK);
			break;
	}
}
