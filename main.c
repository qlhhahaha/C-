#include"common.h"
#include"main.h"

void main(void)
{
	int gdriver=VGA, gmode=VGAHI;
	int pagestate=0;
	USER u;
	memset(&u,'\0',sizeof(USER));
	initgraph(&gdriver, &gmode, "C:\\BORLANDC\\BGI");
	cleardevice();
	mouseinit();

	while (1)
		{
			switch (pagestate)
			{
				case 0:		//��ʼ��ѡ�����
				{
					s_1(&pagestate);    //��ı�pagestate��ֵ����
					memset(&u,'\0',sizeof(USER));
					break;                  //Ҳ���ص�����ͳ�Ϊ�޵�¼״̬
				}

				case 1:		//�˳���ť
				{
					delay(500);//��ʱ0.5s����ֹ�´ν���ʱ������
					closegraph();
					exit(0);//����رտ�ʱ�����˳�
				}

				case 2:		//ʹ��˵������
				{
					s_0_1(&pagestate);
					break;
				}

				case 3:		//�������ǽ���
				{
					s_0_2(&pagestate);
					break;
				}

				case 4:		//���ѡ�����
				{
					s_1_1(&pagestate);
					break;
				}

				case 5:		//���˼������¼����
				{
					s_1_2_1(&pagestate,&u);
					break;
				}

				case 6:		//����Ա��½����
				{
					s_1_2_2(&pagestate);
					break;
				}

				case 7:		//���˼�����ע�ắ��
				{
					s_1_3(&pagestate);
					break;
				}

				case 8:	//��ҳ�溯��
				{
					s_2(&pagestate);
					break;
				}
				
				case 9:	//��������ҳ�溯��
				{
					s_1_4(&pagestate);
					break;
				}
				
			}
		}
}



