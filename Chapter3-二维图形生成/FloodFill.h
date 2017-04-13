/******************************************************************************************
* 计算机图形学基础（OpenGL版）	--	漫水法填充(Flood-Fill-Algorithm)
* 丁酉鸡年三月 2017/4/5 10:41
* @author 西唐王, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once

#include "../OpenGL/Util.h"

void FloodFill_R(int x, int y, Color3f * newColor, Color3f * boundaryColor)
{
	// 当处理内定义区域时，用if(getpixel(x,y) != newcolor)判断即可
	if (getpixel(x, y)->operator!=(newColor) && getpixel(x, y)->operator!=(boundaryColor))
	{
		setpixel(x, y, newColor);
	}
}
