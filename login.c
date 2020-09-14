#include"common.h"
#include"drawfun.h"
#include"login.h"
#include"drawpage.h"
#include"loginfun.h"
#include"hz.h"

void s_1(int *pagestate)
{
	g_1();//��ӭҳ��1��ͼ����
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if (mouse_press(30,300,180,360)==1)
		{
			*pagestate=4;//��½�����ѡ��
			return;
		}
		if (mouse_press(245,300,395,360)==1)
		{
			*pagestate=2;//ʹ��˵��
			return;
		}
		if (mouse_press(460,300,610,360)==1)
		{
			*pagestate=3;//��������
			return;
		}
		if (mouse_press(605,5,635,35)==1)
		{
			*pagestate=1;//�˳�
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
	g_1_1();//���ѡ��ҳ��1_1��ͼ����
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if (mouse_press(240,170,400,220)==1)
		{
			*pagestate=5;//���˵�½ҳ��
			return;
		}
		if (mouse_press(240,260,400,310)==1)
		{
			*pagestate=5;//�����½ҳ��
			return;
		}
		if (mouse_press(240,350,400,400)==1)
		{
			*pagestate=6;//����Ա��½ҳ��
			return;
		}
		if (mouse_press(605,5,635,35)==1)
		{
			*pagestate=0;//���ر���ҳ��
			delay(500);
			return;
		}
	}
}

/**********************************************
FUNCTION:s_1_2_1
DESCRIPTION���û����������˺����壩��¼�������
INPUT:pagestate,u
RETURN:��
***********************************************/
void s_1_2_1(int *pagestate,USER *u)
{
	int num;
	int state1 = 0;
	int state2 = 0;
	memset(u,'\0',sizeof(USER));   //���𴦴�������u����
	clrmous(MouseX, MouseY);
	delay(100);
	g_1_2();

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX >100 && MouseX < 540 && MouseY>100 && MouseY < 150)
		{
			if (mouse_press(100,100,540,150) == 2)//�û�����δ���
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)//��ֹ���ظ�����
				{
					lightbutton_login(100,100,540,150, LIGHTCYAN, LIGHTGRAY, 1);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					num = 1;
				}
				continue;
				//��������
			}

			else if (mouse_press(100,100,540,150) == 1)//�û�������
			{
				MouseS = 0;
				lightbutton_login(100,100,540,150, LIGHTCYAN, LIGHTGRAY, 1);
				u->userid[0] = '\0';
				inputadmin(u->userid,120,110,11, LIGHTGRAY);//������ַ����������xy��������ַ����ƣ���������ɫ
				//���뺯��
				if(strlen(u->userid) != 0)
					state1 = 1;
				else 
					state1 = 0;
				continue;
			}
		}
		
		if (MouseX >100 && MouseX < 540 && MouseY>250 && MouseY < 300)
		{
			if (mouse_press(100,250,540,300) == 2)//�����δ���
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightbutton_login(100,250,540,300, LIGHTCYAN, LIGHTGRAY, 1);//��������
					num = 2;
				}
				continue;
			}
			else if (mouse_press(100,250,540,300) == 1)//�������
			{
				MouseS = 0;
				lightbutton_login(100,250,540,300, LIGHTCYAN, LIGHTGRAY, 1);
				u->password[0] = '\0';
				inputpassword(u->password,120,260,10, LIGHTGRAY);
				//���뺯��
				if(strlen(u->password) != 0)
					state2 = 1;
				else 
					state2 = 0;
				continue;
			}
		}
		
		if (MouseX >250 && MouseX < 360 && MouseY>310 && MouseY < 330)
		{
			if (mouse_press(250,310,360,330) == 2)//��������δ���
			{
				MouseS = 2;
			}
			else if (mouse_press(250,310,360,330) == 1)//����������
			{
				MouseS = 0;
				*pagestate=9;
				return;
				//�л��������������
			}
		}
		
		if (MouseX > 110 && MouseX < 260 && MouseY>350 && MouseY < 430)
		{
			if (mouse_press(110,350,260,430) == 2)//��¼��δ���
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(110,350,260,430, LIGHTCYAN, LIGHTGRAY, 2);//��������
					num = 3;
				}
				continue;
			}
			else if (mouse_press(110,350,260,430) == 1)//��¼����
			{
				MouseS = 0;
				if (login_complete(u->userid, u->password))     //��Ϣ��ȷ
				{
					if (input_uinfo(u))  //����Ϣ����uָ��
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
				//����¼״̬����
			}
		}
		
		if (MouseX > 380 && MouseX < 530 && MouseY>350 && MouseY < 430)
		{
			if (mouse_press(380,350,530,430) == 2)//ע���δ���
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(380,350,530,430, LIGHTCYAN, LIGHTGRAY, 3);//��������
					num = 5;
				}
				continue;
			}
			else if (mouse_press(380,350,530,430) == 1)//ע�����
			{
				MouseS = 0;
				*pagestate = 7;
				return;
				//�л����û�ע�����
			}
		}

		if (mouse_press(605,5,635,35) == 1)//���ؿ���
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
				recoverbutton_login(1);//�ָ���ť��ɫ
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
DESCRIPTION������Ա��¼�������
INPUT:pagestate,u
RETURN:��
***********************************************/
void s_1_2_2(int *pagestate)
{
	int num;
	int state = 0;
	char A[15] = { '\0' };	//����Ա�˺�
	char P[10] = { '\0' };	//����Ա����
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
			if (mouse_press(100,100,540,150) == 2)//����Ա��δ���
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)//��ֹ���ظ�����
				{
					lightbutton_login(100,100,540,150, LIGHTCYAN, LIGHTGRAY, 1);//color1Ϊ�߿�ɫ��color2Ϊ���ɫ
					num = 1;
				}
				continue;
				//��������
			}
			else if (mouse_press(100,100,540,150) == 1)//����Ա����
			{
				MouseS = 0;
				lightbutton_login(100,100,540,150, LIGHTCYAN, LIGHTGRAY, 1);
				A[0] = '\0';
				inputadmin(A, 120,110, 12, DARKGRAY);
				//���뺯��
				if(strlen(A) != 0)
					state1 = 1;
				else 
					state1 = 0;
				continue;
			}
		}
		if (MouseX >100 && MouseX < 540 && MouseY>250 && MouseY < 300)
		{
			if (mouse_press(100,250,540,300) == 2)//�����δ���
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightbutton_login(100,250,540,300, LIGHTCYAN, LIGHTGRAY, 1);//��������
					num = 2;
				}
				continue;
			}
			else if (mouse_press(100,250,540,300) == 1)//�������
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
				//���뺯��
			}
		}
		if (MouseX > 110 && MouseX < 260 && MouseY>350 && MouseY < 430)
		{
			if (mouse_press(110,260,350,430) == 2)//��¼��δ���
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(110,260,350,430, WHITE, LIGHTBLUE, 2);//��������
					num = 3;
				}
			continue;
			}
			else if (mouse_press(110,260,350,430) == 1)//��¼����
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
				//����Ƿ���¼�����ݿ�Ĺ���Ա������

			}
		}
		
		if (mouse_press(605,5,635,35) == 1)//���ؿ���
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
				recoverbutton_login(1);//�ָ���ť��ɫ
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
DESCRIPTION���û���¼���水ť����
INPUT:x,y,x1,y1,color1,color2,flag
RETURN:��
***********************************************/
void lightbutton_login(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(100);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//���߿�
	switch (flag)
	{
		case 1:
			break;
		case 2:
			puthz(120,360, "��¼", 32, 50, WHITE);
			break;
		case 3:
			puthz(390,360, "ע��", 32, 50, WHITE);
			break;
		default:
			closegraph();
			printf("something runs wrong in lightbutton");
			exit(1);
	}
}

/*********************************************
FUNCTION:recoverbutton_login
DESCRIPTION���û���¼���水ť�����ָ�
INPUT:status
RETURN:��
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
		puthz(70,120,"�˺�",32,50,WHITE);
		break;
	case 2:
		bar(60,250,540,300);
		rectangle(60,250,540,300);
		puthz(70,270,"����",32,50,WHITE);
		break;
	case 3:
		setfillstyle(SOLID_FILL, RED);
		bar(110,350,260,430);
		puthz(150,380,"��½",48,80,WHITE);
		break;
	case 4:
		setfillstyle(SOLID_FILL, RED);
		bar(380,350,530,430);
		puthz(420,380,"ע��",48,80,WHITE);
		break;
	}
}





