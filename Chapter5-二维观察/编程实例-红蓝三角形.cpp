/******************************************************************************************
* 计算机图形学基础（OpenGL版）	--	图形变换的矩阵处理
* 丁酉鸡年四月 2017/5/2 9:23
* @author 西唐王, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
*******************************************************************************************/

#include"gl/glut.h"
typedef GLfloat point2d[2]; // a point data type

void triangle(point2d a,point2d b,point2d c) // display a triangle
{
	glBegin(GL_TRIANGLES);
	glVertex2fv(a);
	glVertex2fv(b);
	glVertex2fv(c);
	glEnd();
}

void display(void)
{
	point2d v[3] = { {-1.0,-0.58},{1.0,-0.58},{0.0,1.15} };
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	glViewport(0, 0, 300, 400);
	triangle(v[0], v[1], v[2]);
	glColor3f(1.0, 0.0, 0.0);
	glViewport(300, 0, 300, 400);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	triangle(v[0], v[1], v[2]);
	glFlush();
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0, 1.0, 1.0,1.0);
}

void main(int argc,char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 400);
	glutCreateWindow("Triangle");

	glutDisplayFunc(display);
	init();

	glutMainLoop();
}