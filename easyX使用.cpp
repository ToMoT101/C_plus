#include<stdio.h>
#include<graphics.h>//����ͷ�ļ�
int main()
{
	BeginBatchDraw();//��ʼ��ͼ

	//ע���Զ�����ɫ��RGB(����ֵ)
	initgraph(800,600);//���ô���(��,��,(��ʽ) )
	//��ʽ�У�SHOWCONSOLE-��ʾ����̨,NOCLOSE-�޹رչ���,NOMINIMIZE-����С������
	//����붼ʵ��(һ�㲻��)�������
	//initgraph(800,600,SHOWCONSOLE|NOCLOSE|NOMINIMIZE)

	setbkcolor(BLACK);//���ñ�����ɫ
	cleardevice();//����
	//�ȱ�����ɫ��������

	//��ͼ(ͼ����״)��
	
	//���úú�Ż�Բ�����úú�Ż�Բ�����úú�Ż�Բ��

	//circle-Բ��ellipse-��Բ,pie-���Σ�polygon-�����
	//rectangle-���Σ�roundrect-Բ�Ǿ��Σ�line-�ߣ�putpixel-��
	
	//���¶���ԲΪ�������Ų���Ϊ����(x,y)�Ͱ뾶�������Ͻ�Ϊ��0,0��
	//circle()-����䣬fillcircle()-�б߿���䣬solidcircle()-�ޱ߿���䣬��ʵ��Բ
	//���磺circle(200, 300, 120)
	

	//����Բ�������ɫ��setfillcolor(WHITE)
	//���ñ߿���ɫ��setlinecolor(BLUE)
	//���ñ߿���ʽ��setlinestyle(��ʽ�����)
	//��ʽ�У�PS_SOLID-ʵ��,PS_DASH-����,PS_DOT-��,PS_DASHDOT-�ߵ�,PS_DASHDOTDOT-�ߵ��
	 
	

	//�ڴ����ڻ�������
	//settextcolor(��ɫ)
	//outtextxy(x,y,�ַ���)
	//settextstyle(�߶ȣ�ƽ����ȣ���������)
	// ע��ƽ�����Ϊ0�����������Ӧ���������ƣ�������
	// 
	//textheight()-��ȡ�ַ���ʵ��ռ�����ظ߶�
	//textwidth()-��ȡ�ַ���ʵ��ռ�����ؿ��
	// ����ˮƽ�ʹ�ֱ����
	// 
	//setbkmode(TRANSPARENT)-�����ֱ������ó�͸����

	//���úú��д�֣����úú��д�֣����úú��д�֣�


	//ʵ�����£�

	//setfillcolor(RGB(129, 42, 48));//�����ɫΪ���Զ���
	setlinestyle(PS_SOLID,4);//�߿�Ϊ��ʵ�ߣ�8�����ص�Ŀ��
	setlinecolor(BLUE);//�߿���ɫΪ����ɫ
	//fillcircle(200, 300, 100);//�������߿��Բ

	char str[] = "����ʵ��";
	settextcolor(RGB(30, 30, 30));//������ɫΪ���Զ���
	settextstyle(15, 9, "����");
	
	setbkmode(TRANSPARENT);//�����ֱ�����Ϊ͸��
	fillrectangle(160, 300, 360, 350);//���߿����
	//�������
	int x = textwidth(str);
	int y = textheight(str);
	//����ߵĳ���-���ֵĳ���=���־��볤��ߵľ���
	int width  = (360-160) / 2 - x / 2;
	int height = (350-300) / 2 - y / 2;
	outtextxy(160+width,300+height,str);//ȷ�����е����꣬�����
	//˭������˭�ں��棬������ȴ��ֺ�ͼ���ص�ʱ���Ὣ�ָ��ǣ�����Ҫ�Ȼ�ͼ�ٴ���


	EndBatchDraw();			//������ͼ


	//�����������������е�
	getchar();
	closegraph();//�رմ���


	

	
}