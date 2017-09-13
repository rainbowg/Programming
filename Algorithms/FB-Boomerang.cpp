/*
输入:没有重复点
*/

#include <vector>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;
typedef struct
{
	double x;
	double y;
}Point;


int Boomerang(vector<Point> arr)
{
	int num = 0;
	vector<double> len;
	map<double, vector<Point>> dis;
	map<double, vector<Point>>::iterator mit;
	vector<Point>::iterator vit;
	double key;
	
	for (int i = 0;i < arr.size();i++)
	{
		//以i为中心计算与i相同距离的点，并以距离为Key值存储据距离相同的点
		for (int j = 0;j < arr.size();j++)
		{
			key = sqrt(pow(arr.at(i).x - arr.at(j).x, 2) + pow(arr.at(i).y - arr.at(j).y, 2));
			dis[key].push_back(arr.at(j));
		}
		for (mit = dis.begin();mit != dis.end();mit++)
		{
			num += (mit->second).size() * ((mit->second).size() - 1);
		}
		dis.clear();
	}

	return num;
}

//void main()
//{
//	cout << Boomerang({ {0,0},{1,0},{2,0},{0,1},{2,1} });
//	system("pause");
//}