/******************************************************************************************
* 计算机图形学基础（OpenGL版）	--	Bresenham直线算法
* 丁酉鸡年三月 2017/3/29 12:49
* @author 西唐王, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once
#include "../OpenGL/Util.h"
#include <cmath>

void LineBres(int x1,int y1,int x2,int y2,Color3f* color = nullptr)
{
	setpixel(x1, y1, color);
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	if (dx == 0 && dy == 0) // 如果点一和点二重合，则不处理
		return;
	int flag = 0; // 标记斜率是否|k| < 1
	if(dx < dy) // 下面将斜率变化至0<=|k|<=1区间
	{
		flag = 1;
		swap_vlaue(&x1, &y1);
		swap_vlaue(&x2, &y2);
		swap_vlaue(&dx, &dy);
	}

	int tx = (x2 - x1) > 0 ? 1 : -1; // 判断x和y的前进方面
	int ty = (y2 - y1) > 0 ? 1 : -1;
	int curx = x1;
	int cury = y1;
	int dS = 2 * dy; // D(i) < 0时，D(i+1)的递增值
	int dT = 2 * (dy -dx); // ---D(i) >= 0---
	int d = dS - dx; // 第一个点的d值
	while (curx != x2)
	{
		if (d < 0)
			d += dS;
		else
		{ cury += ty;d += dT; }
		if (flag) // 如果斜率|k| > 1，还要配合上面，将x,y反转
			setpixel(cury, curx, color);
		else
			setpixel(curx, cury, color);
		curx += tx;
	}
}