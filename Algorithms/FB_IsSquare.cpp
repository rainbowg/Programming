/*
Facebook(九章)：
给定二维平面内四个点，判断这四个点是否能组成正方形，坐标(x,y)为整数。输入的整数范围为[-10000,10000]

样例：
input:
p1=[0,0], p2=[1,1], p3=[1,0], p4=[0,1]
output:
True

思路：
正方形的特征，四条边长度相等，对角线长度相等，且对角线长度大于边长。
输入范围的意义在于求两点长度是该用什么类型存储。
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef struct
{
	int x;
	int y;
}Point;
typedef vector<Point> Points;
typedef map<double, unsigned int> Lengths;

double GetLength(Point p1, Point p2)
{
	// 防止开根号后数字表示不正确
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

bool IsSquare(Points points)
{
	Lengths lens;
	double length;
	for (int i = 1;i < points.size();i++)
	{
		for (int j = 0;j < i;j++)
		{
			length = GetLength(points[i], points[j]);
			if (lens.find(length) != lens.end())
				lens[length] += 1;
			else
				lens[length] = 1;
		}
	}
	if (lens.size() == 2 && lens.begin()->first != lens.rbegin()->first)
	{
		if ((lens.begin()->second == 2 && lens.rbegin()->second == 4) 
			||(lens.begin()->second == 4 && lens.rbegin()->second == 2))
			return true;
	}
	return false;
}

//
//void main()
//{
//	Point p1, p2, p3, p4;
//	p1.x = 0; p1.y = 2;
//	p2.x = 1; p2.y = 1;
//	p3.x = 1; p3.y = 0;
//	p4.x = 0; p4.y = 1;
//	Points points;
//	points.push_back(p1);
//	points.push_back(p2);
//	points.push_back(p3);
//	points.push_back(p4);
//	int i;
//
//	if (IsSquare(points))
//		cout << "is square!" << endl;
//	else
//		cout << "is not square!" << endl;
//
//	cin >> i;
//}