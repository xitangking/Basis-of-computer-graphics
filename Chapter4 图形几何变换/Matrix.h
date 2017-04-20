/******************************************************************************************
* 计算机图形学基础（OpenGL版）	--	图形变换的矩阵处理
* 丁酉鸡年三月 2017/4/13 22:43
* @author 西唐王, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

#pragma once
#include<cmath>
#include<vector>

using namespace std;

class TransformMatrix
{
protected:
	float ** matrix;
	float ** temp_matrix;
	int dimension;

	virtual void set(float * m[])
	{
		for(int i = 0;i < dimension;i++)
		{
			for (int j = 0; j < dimension; ++j)
			{
				matrix[i][j] = m[i][j];
			}
		}
	}

	/*void clearTemp()
	{
		for (int i = 0;i < dimension;i++)
		{
			for (int j = 0; j < dimension; ++j)
			{
				temp_matrix[i][j] = 0;
			}
		}
	}*/

public:

	TransformMatrix(int dim)
	{
		dimension = dim;

		matrix = new float*[dimension];
		temp_matrix = new float*[dimension];
		for (int i = 0;i < dimension;++i)
		{
			matrix[i] = new float[dimension];
			temp_matrix[i] = new float[dimension];
		}
		for (int i = 0;i < dimension;i++)
		{
			for (int j = 0; j < dimension; ++j)
			{
				if (i == j)
					matrix[i][j] = 1;
				else
					matrix[i][j] = 0;
				temp_matrix[i][j] = 0;
			}
		}
	}

	// (1)平移变换（以原点为基准点）
	virtual TransformMatrix & translation(float l, float m) = 0;
	virtual TransformMatrix & translation_converse(float l, float m) = 0;
	// (2)旋转变换（以原点为基准点）
	virtual TransformMatrix & rotation(float thita) = 0;
	virtual TransformMatrix & rotation_converse(float thita) = 0;
	// (3)缩放变换（以原点为基准点）
	virtual TransformMatrix & scaling(float a, float d) = 0;
	virtual TransformMatrix & scaling_converse(float a, float d) = 0;
	// (4)反射变换
		// 关于x轴的反射
	virtual TransformMatrix & reflection_x() = 0;
		// 关于y轴的反射
	virtual TransformMatrix & reflection_y() = 0;
		// 关于原点的反射
	virtual TransformMatrix & reflection_0_0() = 0;
		// 关于y = x的反射
	virtual TransformMatrix & reflection_x_y() = 0;
		// 关于y = -x的反射
	virtual TransformMatrix & reflection_y_x() = 0;
	// (5)错切变换
		// 相对于 y = y_ref 的x方向错切
	virtual TransformMatrix & shear_y(float sh_x, float y_ref) = 0;
		// 相对于 x = x_ref 的y方向错切
	virtual TransformMatrix & shear_x(float sh_y, float x_ref) = 0;

	TransformMatrix & operator*(TransformMatrix & right)
	{
		for (int i = 0;i < dimension;i++)
		{
			for (int j = 0; j < dimension; ++j)
			{
				temp_matrix[i][j] = 0;
				for(int k = 0;k < dimension;++k)
				{
					temp_matrix[i][j] += matrix[i][k] * right.matrix[k][j];
				}
			}
		}
		set(temp_matrix);
		return *this;
	}
};

class TransformMatrix2D:public TransformMatrix
{


	void transform(float right[3][3])
	{
		for (int i = 0;i < dimension;i++)
		{
			for (int j = 0; j < dimension; ++j)
			{
				temp_matrix[i][j] = 0;
				for (int k = 0;k < dimension;++k)
				{
					temp_matrix[i][j] += matrix[i][k] * right[k][j];
				}
			}
		}
		set(temp_matrix);
	}

public:
	TransformMatrix2D():TransformMatrix(3)
	{
		
	}

	float ** transform(int num ,float right[][3])
	{
		float ** temp = new float*[num];
		for (int i = 0;i < num;++i)
			temp[i] = new float[3];

		for (int i = 0;i < num;i++)
		{
			for (int j = 0; j < dimension; ++j)
			{
				temp[i][j] = 0;
				for (int k = 0;k < dimension;++k)
				{
					temp[i][j] += matrix[k][j] * right[i][k];
				}
			}
		}
		return temp;
	}

	virtual TransformMatrix2D & translation(float l, float m)
	{
		float  translation[3][3] =
		{
			1, 0, 0,
			0, 1, 0,
			l, m, 1
		};
		transform(translation);
		return *this;
	}

	virtual TransformMatrix2D & translation_converse(float l, float m)
	{
		float translation_converse[3][3] =
		{
			1, 0, 0,
			0, 1, 0,
			-l,-m, 1
		};
		transform(translation_converse);
		return *this;
	}

	virtual TransformMatrix2D & rotation(float thita)
	{
		float rotation[3][3] =
		{
			cos(thita), sin(thita), 0,
			-sin(thita), cos(thita), 0,
			0 ,          0, 1
		};
		transform(rotation);
		return *this;
	}

	virtual TransformMatrix2D & rotation_converse(float thita)
	{
		float rotation[3][3] =
		{
			cos(thita), sin(thita), 0,
			-sin(thita), cos(thita), 0,
			0 ,          0, 1
		};
		transform(rotation);
		return *this;
	}
	// (3)缩放变换（以原点为基准点）
	virtual TransformMatrix2D & scaling(float a, float d)
	{
		float scaling[3][3] =
		{
			a, 0, 0,
			0, d, 0,
			0, 0, 1
		};
		transform(scaling);
		return *this;
	}
	virtual TransformMatrix2D & scaling_converse(float a, float d)
	{
		float scaling_converse[3][3] =
		{
			1 / a,   0, 0,
			0,   1 / d, 0,
			0,       0, 1
		};
		transform(scaling_converse);
		return *this;
	}
	// (4)反射变换
	// 关于x轴的反射
	virtual TransformMatrix2D & reflection_x()
	{
		float reflection_x[3][3] =
		{
			1, 0, 0,
			0,-1, 0,
			0, 0, 1
		};
		transform(reflection_x);
		return *this;
	}
	// 关于y轴的反射
	virtual TransformMatrix2D & reflection_y()
	{
		float reflection_y[3][3] =
		{
			-1, 0, 0,
			 0, 1, 0,
			 0, 0, 1
		};
		transform(reflection_y);
		return *this;
	}
	// 关于原点的反射
	virtual TransformMatrix2D & reflection_0_0()
	{
		float reflection_0_0[3][3] =
		{
			-1, 0, 0,
			0,-1, 0,
			0, 0, 1
		};
		transform(reflection_0_0);
		return *this;
	}
	// 关于y = x的反射
	virtual TransformMatrix2D & reflection_x_y()
	{
		float reflection_x_y[3][3] =
		{
			0, 1, 0,
			1, 0, 0,
			0, 0, 1
		};
		transform(reflection_x_y);
		return *this;
	}
	// 关于y = -x的反射
	virtual TransformMatrix2D & reflection_y_x()
	{
		float reflection_y_x[3][3] =
		{
			0,-1, 0,
			-1, 0, 0,
			0, 0, 1
		};
		transform(reflection_y_x);
		return *this;
	}
	// (5)错切变换
	// 相对于 y = y_ref 的x方向错切
	virtual TransformMatrix2D & shear_y(float sh_x, float y_ref)
	{
		float shear_y[3][3] =
		{
			1, 0,	0,
			sh_x, 1,	0,
			-(sh_x*y_ref), 0, 1
		};
		transform(shear_y);
		return *this;
	}
	// 相对于 x = x_ref 的y方向错切
	virtual TransformMatrix2D & shear_x(float sh_y, float x_ref)
	{
		float shear_x[3][3] =
		{
			1,	     sh_y,	 0,
			0,			1,	 0,
			0,-(sh_y*x_ref), 1
		};
		transform(shear_x);
		return *this;
	}

	TransformMatrix2D & Scale(int xc, int yc, float scale)
	{
		return this->translation_converse(xc, yc).scaling(scale,scale).translation(xc, yc);
	}


};

/*+--+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
// 变换矩阵模板（以行为基准变换矩阵后乘）
/*+--+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/

// 二维几何变换

// (1)平移变换（以原点为基准点）
float l, m;
float translation[3][3] =
{
	1, 0, 0,
	0, 1, 0,
	l, m, 1
};
	//逆变换
float translation_converse[3][3] =
{
	1, 0, 0,
	0, 1, 0,
   -l,-m, 1
};
// (2)旋转变换（以原点为基准点）
float thita;
float rotation[3][3] =
{
	 cos(thita), sin(thita), 0,
	-sin(thita), cos(thita), 0,
			 0 ,          0, 1
};

// (3)缩放变换（以原点为基准点）
float a, d;
float scaling[3][3] = 
{
	  a, 0, 0,
	  0, d, 0,
	  0, 0, 1
};

float scaling_converse[3][3] =
{
	1 / a,   0, 0,
	0,   1 / d, 0,
	0,       0, 1
};

// (4)反射变换
	// 关于x轴的反射
float reflection_x[3][3] = 
{
	1, 0, 0,
	0,-1, 0,
	0, 0, 1
};
	// 关于y轴的反射
float reflection_y[3][3] =
{
	-1, 0, 0,
	 0, 1, 0,
	 0, 0, 1
};
	// 关于原点的反射
float reflection_0_0[3][3] =
{
	-1, 0, 0,
	0,-1, 0,
	0, 0, 1
};
	// 关于y = x的反射
float reflection_x_y[3][3] =
{
	0, 1, 0,
	1, 0, 0,
	0, 0, 1
};
	// 关于y = -x的反射
float reflection_y_x[3][3] =
{
	0,-1, 0,
   -1, 0, 0,
	0, 0, 1
};

// 错切变换
float sh_x, sh_y;
	// 相对于 y = y_ref 的x方向错切
float y_ref;
float shear_y[3][3] =
{
			  1, 0,	0,
		   sh_x, 1,	0,
  -(sh_x*y_ref), 0, 1
};
	// 相对于 x = x_ref 的y方向错切
float x_ref;
float shear_x[3][3] =
{
	1,	     sh_y,	 0,
	0,			1,	 0,
	0,-(sh_y*x_ref), 1
};

/*+--+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
// 变换模板
/*+--+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/

// 以任意点为基准的缩放
void Scale(int xc,int yc,float scale)
{
	
}