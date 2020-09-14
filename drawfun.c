#include"drawfun.h"
#include"common.h"
#include"hz.h"

/*
���ã������ߺ���
	Linex(int x1,int y1,int x2, int y2,unsigned char color)  
				��������                  ��ɫ
���ã���
���أ���
*/
void Linex(int x1,int y1,int x2, int y2,unsigned char color)      
{
  int i;
  if(x1>=639||x2>=639||y1>=479||y2>=479)
	{
		return;
	}

  if(x1<=0||x2<=0||y1<=0||y2<=0) 
	{
		return;
	}

  if(y1!=y2||x1>x2)     //y1Ҫ��֤��y2���
	{
		return;
	}

  for(i=x1;i<=x2;i++)
	{
		putpixel(i,y1,color);
	}
  return;
}

/*
���ã������ߺ���
	Liney(int x1,int y1,int x2, int y2,unsigned char color)  
				��������                  ��ɫ
���ã���
���أ���
*/
void Liney(int x1,int y1,int x2, int y2,unsigned char color)
{
  int i;
  if(x1>=639||x2>=639||y1>=479||y2>=479)
	{
		return;
	}

  if(x1<=0||x2<=0||y1<=0||y2<=0)
	{
		return;
	}

//x1Ҫ��֤��x2���
  if(x1!=x2||y1>y2)   
	{
		return;
	}

  for(i=y1;i<=y2;i++)
	{
		return;
	}
  return;
}

/*
���ã�����һ���ұߵ�������
	Tri_R(int x,int y,int color)
���ã���
���أ���
*/
void Tri_R(int x,int y,int color)
{
  int i;
  for(i=0;i<=39;i++)
  {
	Liney(x+i,y+(i+1)/2,x+i,y+40-(i+1)/2,color);
  }
}

/*
���ã�����������
	LineThick(int x1,int y1,int x2,int y2,unsigned char color,int thick,int mode)
						��������                   ��ɫ                   ���췽ʽ
���ã���
���أ���
*/
void LineThick(int x1,int y1,int x2,int y2,unsigned char color,int thick,int mode)
{
	int i;
	if(thick<=1)
	{
		return;
	}
	if(mode==1)//��������
	{
		for(i=-thick/2;i<=thick/2;i++)
		{
			if(x1+i>=1&&x2+i>=1&&x1+i<=679&&x2+i<=679)
			{
				line(x1+i,y1,x2+i,y2);
			}
		}
	}
	else 
		if(mode==2)//��������
		{
			for(i=-thick/2;i<=thick/2;i++)
			{
				if(y1+i>=1&&y2+i>=1&&y1+i<=767&&y2+i<=767)
				{
					line(x1,y1+i,x2,y2+i);
				}
			}
		}
	else 
		if(mode==3)//������
		{	
			for(i=-thick;i<=0;i++)
			{
				if(y1+i>=1&&y2+i>=1&&y1+i<=767&&y2+i<=767)
				{
					line(x1,y1+i,x2,y2+i);
				}
			}
		}
	else 
		if(mode==4)//������
		{
			for(i=0;i<=thick;i++)
			{
				if(y1+i>=1&&y2+i>=1&&y1+i<=767&&y2+i<=767)
				{
					line(x1,y1+i,x2,y2+i);
				}
			}
		}
	if(mode==5)//������
	{
		for(i=-thick;i<=0;i++)
		{
			if(x1+i>=1&&x2+i>=1&&x1+i<=1023&&x2+i<=1023)
			{
				line(x1+i,y1,x2+i,y2);
			}
		}
	}
	if(mode==6)//������
	{
		for(i=0;i<=thick;i++)
		{
			if(x1+i>=1&&x2+i>=1&&x1+i<=1023&&x2+i<=1023)
			{
				line(x1+i,y1,x2+i,y2);
			}
		}
	}
	return;
}


/*
���ã��������
	Bar3d(int x1,int y1,int x2,int y2,int x3,int y3,unsigned char color)
			�Խ�����                      ������������    ��ɫ
���ã���
���أ���
*/
void Bar3d(int x1,int y1,int x2,int y2,int x3,int y3,unsigned char color)
{
	if(x3>x2&&y3<y1)//������ƫ��
	{
		bar(x1,y1,x2,y2);
		LineThick( x2, y1, x3, y3, color-1, y2-y1, 4);
		LineThick( x2, y1, x3, y3, color, x2-x1,5);
	}
	if(x3>x2&&y3>y2)//��������
	{
		bar(x1,y1,x2,y2);
		LineThick( x2, y2, x3, y3, color-1, y2-y1, 3);
		LineThick( x2, y2, x3,y3, color, x2-x1,5);
	}
	if(x3<x1&&y3<y1)//������ƫ��
	{
		bar(x1,y1,x2,y2);
		LineThick( x1, y1, x3, y3, color-1, y2-y1, 4);
		LineThick( x1, y1, x3,y3, color, x2-x1,6);
	}
	if(x3<x1&&y3>y2)//������ƫ��
	{
		bar(x1,y1,x2,y2);
		LineThick( x1, y2, x3, y3, color-1, y2-y1, 3);
		LineThick( x1, y2, x3,y3, color, x2-x1,6);
	}
	return;
}


/*
���ã����μ���Ӱ
	Barshadow(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor)
					�Խ�����               ������ɫ                  ��Ӱ��ɫ
���ã���
���أ���
*/
void Barshadow(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor)
{
	bar( x1+5, y1+5, x2+5, y2+5);
	bar( x1, y1, x2, y2);
	return;
}


/*
���ã�ƽ���ı��μ���Ӱ
	LineThickSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick,int mode)
					�Խ�����               ������ɫ                  ��Ӱ��ɫ              �������  ���췽ʽ
���ã���
���أ���
*/
void LineThickSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick,int mode)
{
	LineThick(x1+5,y1+5, x2+5, y2+5,shacolor,thick,mode);
	LineThick(x1,y1, x2, y2,precolor,thick,mode);
	return;
}

/*
���ã������Ӱ
	FrameSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick)
���ã���
���أ���
*/
void FrameSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick)
{
	Frame(x1+5,y1+5, x2+5,y2+5,shacolor,thick);
	Frame(x1,y1, x2,y2,precolor,thick);
	return;
}


//��
void Frame(int x1,int y1,int x2,int y2,unsigned char color,int thick)
{
	if(x1<=0||x1>=640||x2<=0||x2>=640||y1<=0||y1>=480||y2<=0||y2>=480)
	{
		return;
	}
	if(x1>=x2||y1>=y2)
	{
		return;
	}
	bar(x1,y1,x2,y1+thick);
	bar(x1,y2-thick,x2,y2);
	bar(x1,y1,x1+thick,y2);
	bar(x2-thick,y1,x2,y2);
	return;
}

//��ͷ
void Arrow(int x,int y,unsigned char color,int mode)
{
	int i,k=5;
	if(mode==1)//x��y,x+50,y+50
	{
		bar(x+15+k,y+25+k,x+35+k,y+30+k);
		bar(x+30+k,y+5+k,x+35+k,y+30+k);
		bar(x+10+k,y+5+k,x+35+k,y+10+k);
		for(i=1;i<=10;i++)
		{
			Liney(x+10-i+k,y-2+i+k,x+10-i+k,y+18-i+k,25);
		}
		bar(x+15,y+25,x+35,y+30);
		bar(x+30,y+5,x+35,y+30);
		bar(x+10,y+5,x+35,y+10);
		for(i=1;i<=10;i++)
		{
			Liney(x+10-i,y-2+i,x+10-i,y+18-i,color);
		}
		
	}
	else 
		if(mode==2)//���μ�ͷ
		{
			LineThick(x+5,y+5, x+20+5, y+20+5,25,10,6);
			LineThick(x+5,y+40+5, x+20+5, y+20+5,25,10,6);
			LineThick(x,y, x+20, y+20,color,10,6);
			LineThick(x,y+40, x+20, y+20,color,10,6);
		}
	return;
}