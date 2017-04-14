/******************************************************************************************
* 计算机图形学基础（OpenGL版）	--	漫水法填充(Flood-Fill-Algorithm)
* 丁酉鸡年三月 2017/4/5 10:41
* @author 西唐王, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once

#include "../OpenGL/Util.h"
#include <stack>

using namespace std;

class Pixel
{
public:
	int x, y;
	Color3ub * color;
	Pixel(int x = 0, int y = 0, Color3ub * color = nullptr) :x(x), y(y)
	{ 
		this->color = getpixelcolor3ub(x, y);
	}
};

void FloodFill_R(int x, int y, Color3ub * newColor, Color3ub * boundaryColor)
{
	// 当处理内定义区域时，用if(getpixel(x,y) != newcolor)判断即可
	if (getpixelcolor3ub(x, y)->operator!=(newColor) && getpixelcolor3ub(x, y)->operator!=(boundaryColor))
	{
		setpixel_3ub(x, y, newColor);
		FloodFill_R(x - 1, y, newColor, boundaryColor);
		FloodFill_R(x, y + 1, newColor, boundaryColor);
		FloodFill_R(x + 1, y, newColor, boundaryColor);
		FloodFill_R(x, y - 1, newColor, boundaryColor);
	}
}

void FloodFill_I(int x, int y, Color3ub * newColor, Color3ub * boundaryColor)
{
	stack<Pixel> Stack;
	Pixel pixel;
	Stack.push(Pixel(x, y));
	while (!Stack.empty())
	{
		pixel = Stack.top(); Stack.pop();
		if (pixel.color->operator!=(newColor) && pixel.color->operator!=(boundaryColor))
		{
			int xx = pixel.x; int yy = pixel.y;
			setpixel_3ub(xx, yy, newColor);
			Stack.push(Pixel(xx - 1, yy));
			Stack.push(Pixel(xx, yy + 1));
			Stack.push(Pixel(xx + 1, yy));
			Stack.push(Pixel(xx, yy - 1));
		}
	}
}
//
//void zzFill(int startX, int startY, int r, int g, int b) {
//	stack<Point> pixelStack;
//	//x,y是给定的种子像素点，rgb就是要填充的颜色的RGB值
//	Point point = { startX,startY };
//	pixelStack.push(point);
//	int saveX;
//	int xRight, xLeft;
//	int x, y;
//	//如果栈不为空
//	while (!pixelStack.empty()) {
//		//获取最顶端的元素
//		Point tempPoint = pixelStack.top();
//		//删除最顶端的元素
//		pixelStack.pop();
//		saveX = tempPoint.x;
//		x = tempPoint.x;
//		y = tempPoint.y;
//		glReadPixels(x + halfWidth, y + halfHeight, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &iPixel);
//		//如果没有到达右边界，就填充
//		while (!sameColor(iPixel[0], iPixel[1], iPixel[2], borderColor[0], borderColor[1], borderColor[2])) {
//			glPoint(x, y, r, g, b);
//			x = x + 1;
//			glReadPixels(x + halfWidth, y + halfHeight, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &iPixel);
//		}
//		xRight = x - 1;
//		x = saveX - 1;
//		glReadPixels(x + halfWidth, y + halfWidth, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &iPixel);
//		//如果没有到达左边界，就填充
//		while (!sameColor(iPixel[0], iPixel[1], iPixel[2], borderColor[0], borderColor[1], borderColor[2])) {
//			glPoint(x, y, r, g, b);
//			x = x - 1;
//			glReadPixels(x + halfWidth, y + halfWidth, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &iPixel);
//		}
//		//保存左端点
//		xLeft = x + 1;
//		//从右边的点开始
//		x = xRight;
//		//检查上端的扫描线
//		y = y + 1;
//		while (x >= xLeft) {
//			glReadPixels(x + halfWidth, y + halfWidth, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &iPixel);
//			if (!sameColor(iPixel[0], iPixel[1], iPixel[2], borderColor[0], borderColor[1], borderColor[2]) && !sameColor(iPixel[0], iPixel[1], iPixel[2], r, g, b)) {
//				//如果上方的点不是边界点，直接压入
//				Point p = { x,y };
//				pixelStack.push(p);
//				//压入之后停止循环
//				break;
//			}
//			else {
//				x--;
//				glReadPixels(x + halfWidth, y + halfWidth, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &iPixel);
//			}
//		}
//		//检查下端的扫描线
//		y = y - 2;
//		//从右边的点开始
//		x = xRight;
//		while (x >= xLeft) {
//			glReadPixels(x + halfWidth, y + halfWidth, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &iPixel);
//			if (!sameColor(iPixel[0], iPixel[1], iPixel[2], borderColor[0], borderColor[1], borderColor[2]) && !sameColor(iPixel[0], iPixel[1], iPixel[2], r, g, b)) {
//				//如果上方的点不是边界点，直接压入
//				Point p = { x,y };
//				//压入之后停止循环
//				pixelStack.push(p);
//				break;
//			}
//			else {
//				x--;
//				glReadPixels(x + halfWidth, y + halfWidth, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &iPixel);
//			}
//		}
//	}
//}