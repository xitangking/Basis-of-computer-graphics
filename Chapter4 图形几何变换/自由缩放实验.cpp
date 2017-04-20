#include "windows.h"
#include "gl/glut.h"
#include"Matrix.h"

#define PI 3.14159

#define draw_triangle(x1,y1,x2,y2,x3,y3) glBegin(GL_TRIANGLES); \
      glVertex2f(x1,y1); glVertex2f(x2,y2);glVertex2f(x3,y3); glEnd();

#define drawLine(xs,ys,xe,ye)    glBegin(GL_LINES); \
      glVertex2i(xs,ys); glVertex2i(xe,ye); glEnd();


static float Point[3][3] = {
	50.0, 50.0, 1.0,
	150.0, 50.0, 1.0,
	150.0, 120.0, 1.0};

float xp=50.0,yp=50.0;// xp、yp旋转中心。
float scale = 2; // 缩放比例
float change_scale = 0.001;

void init(void){
   glClearColor(0.0,0.0,0.0,0.0);
   glShadeModel(GL_FLAT);
}

/*
void p_rotate(float t){
    int i;
	float x[3],y[3];

	for(i=0;i<3;i++)
	{
		x[i]=(Point[i][0]-xp)*cos(t)-(Point[i][1]-yp)*sin(t)+xp;
		y[i]=(Point[i][0]-xp)*sin(t)+(Point[i][1]-yp)*cos(t)+yp;
	}
	draw_triangle(x[0],y[0],x[1],y[1],x[2],y[2]);
}
*/

void p_scale()
{
	int i;
	float x[3],y[3];
	float ** point;

	//for(i = 0;i < 3;i++)
	//{
	//	x[i] = Point[i][0] * scale + (1 - scale) * xp;  // 按任意点变换的关系式
	//	y[i] = Point[i][1] * scale + (1 - scale) * yp;
	//}
	TransformMatrix2D transform;
	point = transform.Scale(150, 50, scale).transform(3, Point);
	point = transform.rotation(scale - 0.5).transform(3, Point);
	draw_triangle(point[0][0], point[0][1], point[1][0], point[1][1], point[2][0], point[2][1]);
	//draw_triangle(x[0],y[0],x[1],y[1],x[2],y[2]);
}

void display(void){

   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0,1.0,1.0);
   drawLine(-300,0,300,0);
   drawLine(0,-300,0,300);

   glColor3f(1.0,0.8,0.8);
   draw_triangle(Point[0][0],Point[0][1],Point[1][0],Point[1][1],Point[2][0],Point[2][1]);

   p_scale();

   glutSwapBuffers();//交换缓冲显存
}


void changeT(void)
{
	scale = scale + change_scale;
	if(scale>3)
		change_scale = -change_scale;
	if(scale<0.5)
		change_scale = -change_scale;
	glutPostRedisplay();//要求当前的回调函数返回时执行显示回调函数
}

void reshape(int w,int h){
   glViewport(0,0,(GLsizei)w,(GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-w/2,w/2,-h/2,h/2);
}

int main(int argc, char* argv[])
{
	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(100,100);
	glutCreateWindow("绕任意点旋转动画");
	init();
    
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(changeT);

	glutMainLoop();
	
	  return 0;
}