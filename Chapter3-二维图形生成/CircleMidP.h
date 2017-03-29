/******************************************************************************************
* 计算机图形学基础（OpenGL版）	--	中点画圆算法
* 丁酉鸡年三月 2017/3/29 19:56
* @author 西唐王, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once

#include "../OpenGL/Util.h"

// 通过一个点算出其映射的八个点
//void Cirpot(int x0, int y0, int x, int y, Color3f* color = nullptr)
//{
//	setpixel((x0 + x), (y0 + y), color);
//	setpixel((x0 + y), (y0 + x), color);
//	setpixel((x0 + y), (y0 - x), color);
//	setpixel((x0 + x), (y0 - y), color);
//	setpixel((x0 - x), (y0 - y), color);
//	setpixel((x0 - y), (y0 - x), color);
//	setpixel((x0 - y), (y0 + x), color);
//	setpixel((x0 - x), (y0 + y), color);
//}

void CircleMidP(int x0, int y0, int r, Color3f* color = nullptr)
{
	int x = 0;
	int y = r;
	int d = 1 - r;
	Cirpot(x0, y0, x, y, color);
	while (x < y)
	{
		if (d < 0)
			d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
		Cirpot(x0, y0, x, y, color);
	}
}
