/******************************************************************************************
* 计算机图形学基础（OpenGL版）	--	直线算法（逐点比较法）
* 丁酉鸡年二月 2017/3/15 11:18
* @author 西唐王, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#include <cmath>
#include <wincon.h>
#include<GL/glut.h>


void drawPoint(int x,int y)
{
	glBegin(GL_POINTS); 
	glVertex2f(x, y); 
	glEnd();
}

void PrintLine(int x1, int y1, int x2, int y2, int color)
{
	int x, y, xA, yA;
	if(y1>y2)
	{
		yA = y1 - y2;
		xA = x1 - x2;
	}
	else
	{
		yA = y2 - y1;
		xA = x2 - x1;
	}

	int F = x = y = 0;
	int n = abs(xA) + abs(yA);
	for (int i = 0; i < n; ++i)
	{
		if (xA > 0)
		{
			if (F >= 0)
			{
				x++;F -= yA;
			}
			else
			{
				y++;F += xA;
			}
		}
		else
		{
			if(F>= 0)
			{
				y++;F += xA;
			}
			else
			{
				x++;F += yA;
			}
			if (y1 > y2)
			{
				drawPoint(x + x2, y + y2);
			}
			else
			{
				drawPoint(x + x1, y + y1);
			}
		}
	}
}
