/*
Google 种花
给定flowerbed（一个包含0和1的数组，0表示该花槽为空，1表示该花槽已经种了花）
以及一个数n，问是否可以再种下新的n株花且满足相邻花槽不能同时种花的条件。

例子：
输入：flowerbed=[1,0,0,0,1], n=1
输出：ture

输入：flowerbed=[1,0,0,0,1], n=2
输出：false

解题思路：贪心算法
*/

#include <iostream>
#include <vector>

using namespace std;

bool PlantFlower(vector<int> flowerbed, int num)
{
	vector<int> onePos;
	vector<int>::iterator it;
	int i = 0, count=0;

	onePos.push_back(-2);
	for (it = flowerbed.begin(); it < flowerbed.end(); it++, i++)
		if ((*it) == 1)
			onePos.push_back(i);
	onePos.push_back(i+1);

	for (it = onePos.begin() + 1; it < onePos.end(); it++)
		if ((*it) - (*(it-1)) > 2)
		{
			it = onePos.insert(it, (*(it-1)) + 2);
			count++;
		}
	cout << count << endl;
	if (count < num)
		return false;
	return true;
}


//void main()
//{
//	vector<int> flowerbed = {1,0,1,0,0};
//	int i;
//
//	if (PlantFlower(flowerbed, 2))
//		cout << "OK";
//	else
//		cout << "OUT";
//
//	system("pause");
//}