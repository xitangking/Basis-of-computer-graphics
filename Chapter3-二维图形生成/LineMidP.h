/******************************************************************************************
* 计算机图形学基础（OpenGL版）	--	Bresenham中点直线算法
* 丁酉鸡年三月 2017/3/29 18:57
* @author 西唐王, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once

#include "../OpenGL/Util.h"
#include<cmath>

void LineMidP(int x0,int y0,int x1,int y1,Color3f* color = nullptr)
{
	int a, b, d, x, y, flag = 0;
	if (abs(x1 - x0) < abs(y1 - y0)) // 若斜率的绝对值大于1，减x坐标和y坐标互换
	{
		swap_vlaue(&x0, &y0);
		swap_vlaue(&x1, &y1);
		flag = 1;
	}
	if (x0 > x1) // 保证x0 < x1
	{ // 确保x较小的坐标为起始点
		swap_vlaue(&x0, &x1);
		swap_vlaue(&y0, &y1);
	}
	a = y0 - y1;
	b = x1 - x0;
	d = a + b / 2;
	if(y0 < y1) // 斜率为正
	{
		x = x0;y = y0;
		setpixel(x, y, &Color3f(225, 0, 0));
		while (x < x1)
		{
			if(d < 0)
			{
				x++;y++;d = d + a + b;
			}
			else
			{
				x++;d += a;
			}
			if (flag) // 若斜率的绝对值大于1，减x坐标和y坐标互换回来
				setpixel(y, x, color);
			else
				setpixel(x, y, color);
		} /* while */
	}
	else
	{
		x = x1;y = y1;
		setpixel(x, y, &Color3f(255, 0, 0));
		while (x > x0)
		{
			if(d < 0)
			{
				x--;y++;d = d - a + b;
			}
			else
			{
				x--;d -= a;
			}
			if (flag) // 若斜率的绝对值大于1，减x坐标和y坐标互换回来
				setpixel(y, x, color);
			else
				setpixel(x, y, color);
		} /* while */
	}

}