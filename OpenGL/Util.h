/******************************************************************************************
* 计算机图形学(OpenGL版) -- 常用的自定义类及函数
* 丁酉鸡年三月 2017/3/29 11:09
* @author 西唐王, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once
#include <gl/glut.h>

/*+--+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
// 常量
/*+--+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/

#define PI 3.1415926

/*+--+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
// 类
/*+--+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/

class Color3f
{
public:
	float r, g, b;

	Color3f(float r,float g,float b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}

	bool operator=(Color3f * color)
	{
		return color->r == r && color->g == g && color->b == b;
	}


	bool operator!=(Color3f * color)
	{
		return !(color->r == r && color->g == g && color->b == b);
	}
};


/*+--+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
// 函数
/*+--+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/

// 绘图初始化通用 begin

double MAX(double l, double r)
{
	return l > r ? l : r;
}

double MIN(double l, double r)
{
	return l < r ? l : r;
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

// 绘图初始化通用 end

// 基本图形绘制 begin

void setpixel(float x, float y, Color3f* color3_f = nullptr)
{
	if (color3_f != nullptr)
		glColor3f(color3_f->r, color3_f->g, color3_f->b);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

Color3f * getpixel(int x, int y)
{
	float color[3];
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
	return new Color3f(color[0], color[1], color[2]);
}

void glDrawLine(float x1,float y1,float x2,float y2,float a = 0,int size = 1)
{
	glLineWidth(size);
	glBegin(GL_LINES);
	glVertex3f(x1, y1, a);
	glVertex3f(x2, y2, a);
	glEnd();
}

// 基本图形绘制 end

inline void swap_vlaue(int* a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

