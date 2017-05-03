/******************************************************************************************
* 计算机图形学基础（OpenGL版）	--	三角形与矩形的几何变换
* 丁酉鸡年四月 2017/5/3 12:46
* @author 西唐王, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
*******************************************************************************************/

#include"gl/glut.h"
#include<cstdlib>
#include<cmath>

/* 初始化窗口的大小 */
GLsizei winWidth = 600, winHeight = 600;
/* 设置坐标系的显式范围 */
GLfloat xwcMin = 0.0, xwcMax = 225.0;
GLfloat ywcMin = 0.0, ywcMax = 225.0;