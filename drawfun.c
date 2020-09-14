#include"drawfun.h"
#include"common.h"
#include"hz.h"

/*
作用：画横线函数
	Linex(int x1,int y1,int x2, int y2,unsigned char color)  
				两端坐标                  颜色
调用：无
返回：无
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

  if(y1!=y2||x1>x2)     //y1要保证和y2相等
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
作用：画竖线函数
	Liney(int x1,int y1,int x2, int y2,unsigned char color)  
				两端坐标                  颜色
调用：无
返回：无
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

//x1要保证和x2相等
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
作用：画出一个右边的三角形
	Tri_R(int x,int y,int color)
调用：无
返回：无
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
作用：画出粗线条
	LineThick(int x1,int y1,int x2,int y2,unsigned char color,int thick,int mode)
						两端坐标                   颜色                   拉伸方式
调用：无
返回：无
*/
void LineThick(int x1,int y1,int x2,int y2,unsigned char color,int thick,int mode)
{
	int i;
	if(thick<=1)
	{
		return;
	}
	if(mode==1)//左右拉伸
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
		if(mode==2)//上下拉伸
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
		if(mode==3)//上拉伸
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
		if(mode==4)//下拉伸
		{
			for(i=0;i<=thick;i++)
			{
				if(y1+i>=1&&y2+i>=1&&y1+i<=767&&y2+i<=767)
				{
					line(x1,y1+i,x2,y2+i);
				}
			}
		}
	if(mode==5)//左拉伸
	{
		for(i=-thick;i<=0;i++)
		{
			if(x1+i>=1&&x2+i>=1&&x1+i<=1023&&x2+i<=1023)
			{
				line(x1+i,y1,x2+i,y2);
			}
		}
	}
	if(mode==6)//右拉伸
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
作用：立体矩形
	Bar3d(int x1,int y1,int x2,int y2,int x3,int y3,unsigned char color)
			对角坐标                      第三个点坐标    颜色
调用：无
返回：无
*/
void Bar3d(int x1,int y1,int x2,int y2,int x3,int y3,unsigned char color)
{
	if(x3>x2&&y3<y1)//往右上偏移
	{
		bar(x1,y1,x2,y2);
		LineThick( x2, y1, x3, y3, color-1, y2-y1, 4);
		LineThick( x2, y1, x3, y3, color, x2-x1,5);
	}
	if(x3>x2&&y3>y2)//往右下移
	{
		bar(x1,y1,x2,y2);
		LineThick( x2, y2, x3, y3, color-1, y2-y1, 3);
		LineThick( x2, y2, x3,y3, color, x2-x1,5);
	}
	if(x3<x1&&y3<y1)//往左上偏移
	{
		bar(x1,y1,x2,y2);
		LineThick( x1, y1, x3, y3, color-1, y2-y1, 4);
		LineThick( x1, y1, x3,y3, color, x2-x1,6);
	}
	if(x3<x1&&y3>y2)//往左下偏移
	{
		bar(x1,y1,x2,y2);
		LineThick( x1, y2, x3, y3, color-1, y2-y1, 3);
		LineThick( x1, y2, x3,y3, color, x2-x1,6);
	}
	return;
}


/*
作用：矩形加阴影
	Barshadow(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor)
					对角坐标               矩形颜色                  阴影颜色
调用：无
返回：无
*/
void Barshadow(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor)
{
	bar( x1+5, y1+5, x2+5, y2+5);
	bar( x1, y1, x2, y2);
	return;
}


/*
作用：平行四边形加阴影
	LineThickSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick,int mode)
					对角坐标               矩形颜色                  阴影颜色              拉伸距离  拉伸方式
调用：无
返回：无
*/
void LineThickSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick,int mode)
{
	LineThick(x1+5,y1+5, x2+5, y2+5,shacolor,thick,mode);
	LineThick(x1,y1, x2, y2,precolor,thick,mode);
	return;
}

/*
作用：框加阴影
	FrameSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick)
调用：无
返回：无
*/
void FrameSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick)
{
	Frame(x1+5,y1+5, x2+5,y2+5,shacolor,thick);
	Frame(x1,y1, x2,y2,precolor,thick);
	return;
}


//框
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

//箭头
void Arrow(int x,int y,unsigned char color,int mode)
{
	int i,k=5;
	if(mode==1)//x，y,x+50,y+50
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
		if(mode==2)//矩形箭头
		{
			LineThick(x+5,y+5, x+20+5, y+20+5,25,10,6);
			LineThick(x+5,y+40+5, x+20+5, y+20+5,25,10,6);
			LineThick(x,y, x+20, y+20,color,10,6);
			LineThick(x,y+40, x+20, y+20,color,10,6);
		}
	return;
}
