#ifndef_drawfun_h
#define_drawfun_h
#define LENGTH 640
#define WIDTH  480
void Linex(int x1,int y1,int x2,int y2,unsigned char color);//ƽ��x��ֱ��
void Liney(int x1,int y1,int x2,int y2,unsigned char color);//ƽ��y��ֱ��
void Tri_R(int x,int y,int color);//�ұ�������
void LineThick(int x1,int y1,int x2,int y2,unsigned char color,int thick,int mode);//����������
void Barshadow(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor);//���μ�Ӱ��
void LineThickSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick,int mode);//ƽ���ı��μ�Ӱ��
void FrameSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick);//���Ӱ��
void Bar3d(int x1,int y1,int x2,int y2,int x3,int y3,unsigned char color);//3d�����壬�Խ����꣬�Һ��½�����
void Frame(int x1,int y1,int x2,int y2,unsigned char color,int thick);//��
void Arrow(int x,int y,unsigned char color,int mode);//���ּ�ͷ
#endif