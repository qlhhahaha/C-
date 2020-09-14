#ifndef _DATA_H_
#define _DATA_H_

typedef struct userinfo
{
	char userid[15];    //������11λ�������û���
	char password[15];  //������10λ������
	char phone[11];		//������11λ���ֻ���
	long int score;
	int times;
	int achi;
	int usercode;
	int goods[9];
}USER;	//��װ�û���Ϣ

typedef struct admininfo
{
	char userid[15];//������11λ������Ա�˺�
	char password[10];//������10λ������Ա����
}ADMIN;//��װ����Ա��Ϣ

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
}PRO;//��װ��Ŀ��Ϣ

typedef struct reinfo
{
	int procode;
	char userid[15];
	long int amount[9];
}RECORD;//��װ������¼��Ϣ

typedef struct messinfo
{
	char userid[15];
	char text[100];
}MESSAGE;//��װ������Ϣ
#endif