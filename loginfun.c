#include"loginfun.h"
#include"common.h"
#include"hz.h"
#include"database.h"
#include"register.h"

/*********************************************
FUNCTION:admin_judge
DESCRIPTION������Ա����Ƿ�ƥ��
INPUT:admin,pass
RETURN:��
***********************************************/
int admin_judge(char* admin, char* pass)
{
	if (strlen(admin) == 0)
	{
		puthz(550,120, "δ����", 16, 17, RED);
	}
	if (strlen(pass) == 0)
	{
		puthz(550,260, "δ����", 16, 17, RED);
		return 0;
	}
	if ((strcmp(admin, "qlh") == 0
		|| strcmp(admin, "lhy") == 0)
		&&strcmp(pass, "aia1905") == 0)
	{
		puthz(300,440, "��¼�ɹ�", 16, 20, RED);
		return 1;
	}
	else
	{
		puthz(550,120, "����Ա��Ϣ����", 16, 20, RED);
		return 0;
	}
	return 0;
}

/*********************************************
FUNCTION:register_complete
DESCRIPTION�������ж�ע����Ϣ�Ƿ�������ȫ����ȷ
INPUT:u,p,cp,vc,rdvc
RETURN:1/0
***********************************************/
int register_complete(char*u,char *p,char* cp, char* vc,char* rdvc)//rdvcΪrandomvc
{
	int i;
	int state = 0;//�Ƿ�����ı���
	int state1 = 1;//ȷ�������Ƿ�һ�µı���
	int state2 = 1;//��֤���Ƿ�һ�µı���
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
			if (!judge_sameuser(u,1))          //  �����򷵻�0��δ��������1
			{
				state1 = checkright_confirmedpassword(p, cp, 547, 210);
				state2= checkright_verificationcode(rdvc, vc, 547, 330);
				break;
			}
			else if(judge_sameuser(u,2))//�û���û������
			{
				puthz(135, 60, "���õ��û���", 16, 17, RED);
				state1 = checkright_confirmedpassword(p, cp, 547, 210);
				state2 = checkright_verificationcode(rdvc, vc, 547, 330);
				if (state1 != 0 || state2 != 0)
				{
					break;
				}
				else if (state1 == 0 && state2 == 0 )
				{
					input_database(u, p);
					//д�����ݿ�
					puthz(280,420, "ע��ɹ�", 16, 17, RED);
					delay(2000);
					return 1;//����
				}
			}
		}
	}
	return 0;
}


/*********************************************
FUNCTION:input_database
DESCRIPTION�����û�ע����Ϣд���ļ�
INPUT:name,code
RETURN:1/0
***********************************************/
void input_database(char* name, char* code)
{
	FILE* fp;
	USER* u;
	char n;
	if ((fp = fopen("DATABASE\\USER.dat", "rb+" )) == NULL)//�������ݿ�
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
	fseek(fp, 0, SEEK_END);//��ת���ļ�ĩβ
	fwrite(u, sizeof(USER), 1, fp);//���û���Ϣд���ļ�
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
DESCRIPTION���ж��˻��Ƿ��������,
	flagΪ1�ж��Ƿ�ע�ᣬ
	flagΪ2�ж��һ��������Ƿ����
INPUT:new_user,flag
RETURN:1/0
***********************************************/
int judge_sameuser(char* new_user,int flag)
{
	int len;
	int i;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen("DATABASE\\USER.dat", "rb+")) == NULL)//�������ݿ�
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
				puthz(135, 60, "�û��ѱ�ע��", 16, 17, RED);
				break;
			case 2:
				puthz(450, 110, "�˺Ŵ���", 16, 17, RED);
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
DESCRIPTION�����ȷ�������Ƿ�һ��
INPUT:str1,str2,x,y
RETURN:1/0
***********************************************/
int checkright_confirmedpassword(char* str1, char* str2, int x, int y)
{
	if (strcmp(str1, str2) != 0)
	{
		puthz(x, y, "���β�һ��", 16, 17, RED);
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
DESCRIPTION�������֤���Ƿ�һ��
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
		{   //��Сд�ַ�
			if(*cstr2 >= 'a' && *cstr2 <= 'z')     //'A'<'a'
			{
				if(*cstr1 == *cstr2 || *cstr1 == *cstr2 - 32)
				{
					cstr1++;
					cstr2++;
				}  //���һ��
				else
				{
					puthz(x, y, "��֤�����", 16, 17, RED);
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
					puthz(x, y, "��֤�����", 16, 17, RED);
					return 1;
				}
			}
		}
		else //��֤�벻����ĸ
		{
			if(*cstr1 == *cstr2)
			{
				cstr1++;
				cstr2++;
			}
			else
			{
				puthz(x, y, "��֤�����", 16, 17, RED);
				return 1;
			}	
		}
	}
	if(*cstr2 != '\0')
	{
		puthz(x, y, "��֤�����", 16, 17, RED);
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
		puthz(x, y, "��֤�����", 16, 17, RED);
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
DESCRIPTION�������˺š����֤�ŵ��������ص���Ϣ
INPUT:id,x1,y1,charnum,color
RETURN:��
***********************************************/
void inputadmin(char* id, int x1, int y1, int charnum, int color)//������ַ����������xy��������ַ����ƣ���������ɫ
{
	int i = 0;//i���ڼ���
	char t;
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);//����ˮƽ����ʹ�ֱ������ı����뷽ʽ
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);//�������
	while (1)
	{
		t = bioskey(0); //��t��¼��ֵ
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//��t��Ϊ�����ʱ
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //�ڸǹ��
					outtextxy(x1 + 8 + i * 18, y1-1, id + i);//���t�ַ�(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��
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
				if (t == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��  
				break;
			}
		}
	}
}

/*********************************************
FUNCTION:inputpassword
DESCRIPTION���������ܣ������������Ҫ���ص���Ϣ
INPUT:id,x1,y1,charnum,color
RETURN:��
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
		t = bioskey(0);//��ȡ��ֵ
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//033��ʾEsc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
					outtextxy(x1 + 8 + i * 18, y1 + 4, "*");//���*�ַ�
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
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
				if (t == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
				break;
			}
		}
	}
}

/*********************************************
FUNCTION:judge
DESCRIPTION���ж�ע���״̬
INPUT:str,p,x,y
RETURN:��
***********************************************/
void judge(char* str, int* p, int x, int y)
{
	if (strlen(str) == 0)
	{
		*p = 1;
		puthz(x, y, "δ����", 16, 17, RED);
	}
	else
	{
		*p = 0;
	}
}

/*********************************************
FUNCTION:recoverhz
DESCRIPTION�����ڸ��Ǻ���
INPUT:x,y,color
RETURN:��
***********************************************/
void recoverhz(int x, int y,int color)
{
	setfillstyle(SOLID_FILL,color);
	bar(x, y, x + 100, y + 30);
}

/*********************************************
FUNCTION:login_complete
DESCRIPTION�������жϵ�¼��Ϣ�Ƿ�������ȫ����ȷ
INPUT:u,p
RETURN:1/0
***********************************************/
int login_complete(char* u, char* p)
{
	int state1 = 1;//�Ƿ�����ı���
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
DESCRIPTION���ж��û����������Ƿ�ƥ��
	ƥ�����¼
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
	len = ftell(fp) / sizeof(USER);//�����USER�ṹ��ĸ���������ע���û��ĸ���
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
		if (strcmp(name, u->userid) == 0)//�û���ƥ��
		{
			if (strcmp(pass, u->password) != 0)//���벻��
			{
				puthz(550,260, "�������", 16, 17, RED);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				break;
			}
			else if (strcmp(pass, u->password) == 0)//����ƥ��
			{
				puthz(300,440, "��¼�ɹ�", 16, 17, RED);
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
				//�л�����
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
		puthz(550,110, "�˻�δע��", 16, 17, RED);//�ߵ����һλ
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
DESCRIPTION���������ܣ������û���Ϣ
INPUT:us
RETURN:��
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
	fseek(fp, 0, SEEK_END);//�ļ�ָ�붨λ�����һλ
	len = ftell(fp) / sizeof(USER);//�����û�����
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in loginfun.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);//ÿ��������һ���û�
		fread(u, sizeof(USER), 1, fp);		  //����Ϣ����u
		if (strcmp(us->userid, u->userid) == 0)
		{
			memset(us,'\0',sizeof(USER));              //������
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
DESCRIPTION���ж��˺���绰���Ƿ�ƥ�䣬
	���ж���������������Ƿ���ͬ��
	��ƥ������ͬ��д�������롣
INPUT:id,ph,pass,againpass
RETURN:1/0
***********************************************/
int id_phone(char* id, char* ph, char* np, char* cp)
{
	int str;
	int len;//���ڼ����û�����
	int i,j;//���ڼ���
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen("database\\USER.dat", "rb+" )) == NULL)
	{
		printf("cannot open file USER.dat");
		delay(2000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);//�ļ�ָ�붨λ�����һλ
	len = ftell(fp) / sizeof(USER);//�����û�����
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in loginfun.c");
			delay(2000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);//ÿ��������һ���û�
		fread(u, sizeof(USER), 1, fp);//����Ϣ����u
		if (strcmp(id, u->userid) == 0)
		{
			if (strcmp(ph, u->phone) != 0)
			{
				puthz(540,165, "�绰��ƥ��", 16, 20, RED);
				break;
			}
			else if (strcmp(ph, u->phone) == 0)
			{
				if (strcmp(np, cp) == 0)//��������������ͬ
				{
					u->password[0] = '\0';
					strcpy(u->password, np);
					fseek(fp, i * sizeof(USER), SEEK_SET);
					fwrite(u, sizeof(USER), 1, fp);//�޸����һ��Ҫ�ǵ�д������
					puthz(420,415,"�޸ĳɹ�",16,20,RED);
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