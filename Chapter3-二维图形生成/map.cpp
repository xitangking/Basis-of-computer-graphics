/******************************************************************************************
* 计算机图形学基础（OpenGL版）	--	基于OpenGL的地图绘制
* 丁酉鸡年三月 2017/4/13 21:20
* @author 西唐王, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <GL/glut.h>

using namespace std;

class MapPoint
{
public:
	double longitude;
	double latitude;
};

class Polygon
{
public:
	vector<MapPoint> points; // 多边形的顶点序列
};

vector<Polygon*> polys; // 多边形集合
vector<Polygon*> ReadMapData(char* filename)
{
	int PointCount;
	vector<Polygon*> polygons;
	ifstream fs(filename);
	while(fs.eof() != true)
	{
		Polygon* poly = new Polygon;
		fs >> PointCount;
		cout << PointCount << endl;
		for(int i = 0;i < PointCount;i++)
		{
			MapPoint p;
			fs >> p.longitude >> p.latitude;
			poly->points.push_back(p);
		}
		polygons.push_back(poly);
	}
	return polygons;
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	// 用蓝色绘制各省边界
	glColor3f(0.0, 0.0, 1.0);
	// 设置正面为填充模式
	glPolygonMode(GL_BACK, GL_LINE);
	for (int i = 0;i < polys.size();i++)
	{
		vector<MapPoint> points = polys[i]->points;
		glBegin(GL_LINE_LOOP); // 使用闭合曲线方式绘制各省边界
		for (int j = 0;j < points.size();j++)
		{
			glVertex3f(points[j].longitude , points[j].latitude , 0.0);
		}
		glEnd();
	}
	glFlush();
}

void init(void)
{
	// 设置背景颜色
	glClearColor(1.0, 1.0, 1.0, 0.0);
	// 初始化观察值
	glMatrixMode(GL_PROJECTION); // 将矩阵模式设为投影
	glLoadIdentity(); // 对矩阵进行单位化
	glOrtho(70, 140, 0, 60, -1, 1);
	// 构造平行投影矩阵，注意坐标的设置
}

int main(int argc,char** argv)
{
	char* filename = "HenanCounty.txt";
	polys = ReadMapData(filename);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // 单缓存和RGB
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Map");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}