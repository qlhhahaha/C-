#ifndef_drawfun_h
#define_drawfun_h
#define LENGTH 640
#define WIDTH  480
void Linex(int x1,int y1,int x2,int y2,unsigned char color);//平行x轴直线
void Liney(int x1,int y1,int x2,int y2,unsigned char color);//平行y轴直线
void Tri_R(int x,int y,int color);//右边三角形
void LineThick(int x1,int y1,int x2,int y2,unsigned char color,int thick,int mode);//画出粗线条
void Barshadow(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor);//矩形加影子
void LineThickSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick,int mode);//平行四边形加影子
void FrameSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick);//框加影子
void Bar3d(int x1,int y1,int x2,int y2,int x3,int y3,unsigned char color);//3d长方体，对角坐标，右后下角坐标
void Frame(int x1,int y1,int x2,int y2,unsigned char color,int thick);//框
void Arrow(int x,int y,unsigned char color,int mode);//各种箭头
#endif