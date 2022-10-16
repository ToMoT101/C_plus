#include<stdio.h>
#include<graphics.h>//包含头文件
int main()
{
	BeginBatchDraw();//开始画图

	//注：自定义颜色：RGB(具体值)
	initgraph(800,600);//设置窗口(宽,高,(样式) )
	//样式有：SHOWCONSOLE-显示控制台,NOCLOSE-无关闭功能,NOMINIMIZE-无最小化功能
	//如果想都实现(一般不用)，则可以
	//initgraph(800,600,SHOWCONSOLE|NOCLOSE|NOMINIMIZE)

	setbkcolor(BLACK);//设置背景颜色
	cleardevice();//清屏
	//先背景颜色，再清屏

	//画图(图形形状)：
	
	//设置好后才画圆！设置好后才画圆！设置好后才画圆！

	//circle-圆，ellipse-椭圆,pie-扇形，polygon-多边形
	//rectangle-矩形，roundrect-圆角矩形，line-线，putpixel-点
	
	//以下都以圆为例：括号参数为坐标(x,y)和半径，最左上角为（0,0）
	//circle()-无填充，fillcircle()-有边框填充，solidcircle()-无边框填充，即实心圆
	//例如：circle(200, 300, 120)
	

	//设置圆的填充颜色：setfillcolor(WHITE)
	//设置边框颜色：setlinecolor(BLUE)
	//设置边框样式：setlinestyle(样式，宽度)
	//样式有：PS_SOLID-实线,PS_DASH-虚线,PS_DOT-点,PS_DASHDOT-线点,PS_DASHDOTDOT-线点点
	 
	

	//在窗口内绘制文字
	//settextcolor(颜色)
	//outtextxy(x,y,字符串)
	//settextstyle(高度，平均宽度，字体名称)
	// 注：平均宽度为0，则比例自适应；字体名称，如宋体
	// 
	//textheight()-获取字符串实际占用像素高度
	//textwidth()-获取字符串实际占用像素宽度
	// 用于水平和垂直居中
	// 
	//setbkmode(TRANSPARENT)-将文字背景设置成透明的

	//设置好后才写字！设置好后才写字！设置好后才写字！


	//实例如下：

	//setfillcolor(RGB(129, 42, 48));//填充颜色为：自定义
	setlinestyle(PS_SOLID,4);//边框为：实线，8个像素点的宽度
	setlinecolor(BLUE);//边框颜色为：蓝色
	//fillcircle(200, 300, 100);//画出带边框的圆

	char str[] = "这是实例";
	settextcolor(RGB(30, 30, 30));//文字颜色为：自定义
	settextstyle(15, 9, "宋体");
	
	setbkmode(TRANSPARENT);//将文字背景改为透明
	fillrectangle(160, 300, 360, 350);//带边框矩形
	//字体居中
	int x = textwidth(str);
	int y = textheight(str);
	//长或高的长度-文字的长度=文字距离长或高的距离
	int width  = (360-160) / 2 - x / 2;
	int height = (350-300) / 2 - y / 2;
	outtextxy(160+width,300+height,str);//确定居中的坐标，打出字
	//谁先运行谁在后面，即如果先打字后画图，重叠时，会将字覆盖，所以要先画图再打字


	EndBatchDraw();			//结束画图


	//下面两个是主函数中的
	getchar();
	closegraph();//关闭窗口


	

	
}