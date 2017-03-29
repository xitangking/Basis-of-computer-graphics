/******************************************************************************************
* 计算机图形学基础（OpenGL版）	--	Bresenham直线算法
* 丁酉鸡年三月 2017/3/29 12:49
* @author 西唐王, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once
#include "../OpenGL/Util.h"
#include <cmath>

inline void swap_vlaue(int* a,int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void LineBres(int x1,int y1,int x2,int y2,Color3f* color = nullptr)
{
	setpixel(x1, y1, color);
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	if (dx == 0 && dy == 0)
		return;
	int flag = 0;
	if(dx < dy)
	{
		flag = 1;
		swap_vlaue(&x1, &y1);
		swap_vlaue(&x2, &y2);
		swap_vlaue(&dx, &dy);
	}

	int tx = (x2 - x1) > 0 ? 1 : -1;
	int ty = (y2 - y1) > 0 ? 1 : -1;
	int curx = x1;
	int cury = y1;
	int dS = 2 * dy;
	int dT = 2 * (dy -dx);
	int d = dS - dx;
	while (curx != x2)
	{
		if (d < 0)
			d += dS;
		else
		{ cury += ty;d += dT; }
		if (flag)
			setpixel(cury, curx, color);
		else
			setpixel(curx, cury, color);
		curx += tx;
	}
}