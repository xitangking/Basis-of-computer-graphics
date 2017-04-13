/******************************************************************************************
* 计算机图形学基础（OpenGL版）	--	PPC直线算法（逐点比较法 Point by Point comparison method）
* 丁酉鸡年三月 2017/3/29 12:21
* @author 西唐王, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once

#if defined(_WIN32) || defined(WIN32)
#include <windows.h> 
#endif
#include"../OpenGL/Util.h"

void LinePPC(int x1,int y1,int x2,int y2,Color3f* color = nullptr)
{
	int x, y, xA, yA;
	if(y1>y2) // 平移直线的坐标，使y值较小的点位于坐标原点
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
		if(xA > 0) // 若斜率为正,因为经过以上的判断，y肯定是大于零
		{
			if(F >= 0)
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
			if(F >= 0)
			{
				y++;F += xA;
			}
			else
			{
				x--;F += yA;
			}
		}
		if (y1 > y2) // 通过判断使y值较小的点位于坐标原点
			setpixel(x + x2, y + y2);
		else
			setpixel(x + x1, y + y1);
	}
}