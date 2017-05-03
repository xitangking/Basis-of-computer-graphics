/******************************************************************************************
* 计算机图形学基础（OpenGL版）	--	图形的三维观察
* 丁酉鸡年四月 2017/5/3 10:23
* @author 西唐王, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
*******************************************************************************************/


#include<stdlib.h>
#include<gl/glut.h>
#include<stdio.h>

void setupPointers(void)
{

	static GLfloat vertices[] = {

		0.0,-1.0,1.0,1.0,   //0
		1.0,0.0,1.0,1.0,    //1
		1.0,1.414,1.0,1.0,  //2
		0.0,2.414,1.0,1.0,  //3
		-1.0,1.414,1.0,1.0, //4
		-1.0,0.0,1.0,1.0,   //5
		0.0,-1.0,-1.0,1.0,   //6
		1.0,0.0,-1.0,1.0,    //7
		1.0,1.414,-1.0,1.0,  //8
		0.0,2.414,-1.0,1.0,  //9
		-1.0,1.414,-1.0,1.0, //10
		-1.0,0.0,-1.0,1.0    //11
	};


	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(4, GL_FLOAT, 0, vertices);
}

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_SMOOTH);
	setupPointers();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();//清空矩阵
	//gluLookAt(2.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	gluLookAt(10.0, 10.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


	GLuint indices1[6] = { 0, 1, 2, 3 ,4, 5};
	glDrawElements(GL_LINE_LOOP, 6, GL_UNSIGNED_INT, indices1);

	GLuint indices2[4] = { 6, 7, 1, 0 };
	glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_INT, indices2);

	GLuint indices3[4] = { 7, 8, 2, 1 };
	glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_INT, indices3);

	GLuint indices4[4] = { 8, 9, 3 ,2 };
	glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_INT, indices4);

	GLuint indices5[4] = { 9, 10, 4, 3 };
	glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_INT, indices5);

	GLuint indices6[4] = { 10, 11, 5, 4 };
	glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_INT, indices6);

	GLuint indices7[4] = { 11, 6, 0, 5 };
	glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_INT, indices7);

	GLuint indices8[6] = { 6,7,8,9,10,11 };
	glDrawElements(GL_LINE_LOOP, 6, GL_UNSIGNED_INT, indices8);

	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3.0, 3.0, -3.0, 3.0, 0.0, 30.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("绘制自定义立体");
	init();

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}