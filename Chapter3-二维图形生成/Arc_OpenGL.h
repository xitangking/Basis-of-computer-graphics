/******************************************************************************************
* 计算机图形学基础（OpenGL版）	--	中点画圆算法
* 丁酉鸡年三月 2017/3/29 21:15
* @author 西唐王, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once

#include<gl/glut.h>
#include<cmath>
#include "../OpenGL/Util.h"

void Arc_OpenGL(int xc,int yc,double r,double ts,double te)
{
	if (te < ts) // 当终止角比起始角还小时，则将终止角加上2n
		te += 2 * PI; 
	double dt = 0.4 / r; // 利用半径取取角度离散值，使其与半径成反比
	int n = (int)((te - ts) / dt + 0.5);
	double ta = ts;
	int x = xc + int(r * cos(ts));
	int y = yc + int(r * sin(ts));
	glBegin(GL_LINE_STRIP); // 如果绘制整圆，选取GL_LINE_LOOP更好
	glVertex2f(x, y);
	for (int i = 1; i <= n; ++i)
	{
		ta += dt;
		double cost = cos(ta);
		double sint = sin(ta);
		x = int(xc + r * cost);
		y = int(yc + r * sint);
		glVertex2f(x, y);
	}
	glEnd();
}
