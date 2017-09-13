/*
FB-IsConvex
夹角公式：https://zh.wikipedia.org/wiki/%E6%95%B0%E9%87%8F%E7%A7%AF
思路：
不要求输入一定按顺时针还是逆时针，但必须按顺序。
只有相邻的两个夹角是负数，既是凹边形
*/

#include <vector>
#include <iostream>
#include <cmath>
# define M_PI 3.14159265358979323846/* pi */

using namespace std;

typedef struct
{
	double x;
	double y;
}Point;

typedef vector<Point> VecP;

double GetAngle(Point pSrc, Point p1, Point p2)
{
	double angle = 0.0f;
	double va_x = p1.x - pSrc.x;
	double va_y = p1.y - pSrc.y;
	double vb_x = p2.x - pSrc.x;
	double vb_y = p2.y - pSrc.y;
	//double productValue = (va_x * vb_x) + (va_y * vb_y);  // 向量的乘积
	//double va_val = sqrt(va_x * va_x + va_y * va_y);  // 向量a的模
	//double vb_val = sqrt(vb_x * vb_x + vb_y * vb_y);  // 向量b的模
	//double cosValue = productValue / (va_val * vb_val);      // 余弦公式
	//angle = acos(cosValue) * 180 / M_PI;

	double sin = va_x * vb_y - vb_x * va_y;
	double cos = va_x * vb_x + va_y * vb_y;
	angle = atan2(sin, cos) * (180 / M_PI);

	return angle;
}

bool IsConvex(VecP arr)
{
	double fst, sec;

	fst = GetAngle(arr.at(arr.size() - 1), arr.at(0), arr.at(arr.size() - 2));
	sec = GetAngle(arr.at(0), arr.at(1), arr.at(arr.size() - 1));
	if (fst * sec < 0)
		return false;
	sec = fst;
	for (int i = 2;i < arr.size();i++)
	{
		sec = GetAngle(arr.at(i - 1), arr.at(i), arr.at(i - 2));
		if (fst * sec < 0)
			return false;
	}
	return true;
}

//void main()
//{
//	if (IsConvex({ {0,0},{0,10},{10,10},{10,0},{5,5} }))
//		cout << "this shape is convex" << endl;
//	else
//		cout << "this shape is concave" << endl;
//
//	system("pause");
//}























