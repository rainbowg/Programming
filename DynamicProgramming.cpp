/*
5座金矿，10个人。每座金矿要么全挖，要么不挖。
如何能够获取最多的黄金。
5个金矿如下：500金/5人，200金/3人，300金/4人，350金/3人，400金/5人


递归版（从上至下）：
1) 当人数小于所需最少人数时，返回0；
2) 当金矿数量等于1，则直接返回金矿量
3) 递归运算（动态规划），设g[n]为金矿量，p[n]为金矿所需人数,
f[i][j]为当人数为i金矿量为j时最大产量，m为总人数。
   Max(g[n] + f[m-p[n]][n-1], g[m][n-1])

备忘录版（从下至上）：
1) 计算边界值
2) 循环计算后续值
*/


#include <map>
#include <iostream>

using namespace std;


int goldens[] = { 500,200,300,350,400 };
int needNum[] = { 5, 3, 4, 3, 5 };

int MaxValue(int a, int b)
{
	return a > b ? a : b;
}

// recursion Version
int DP_FindMaximumValue(int personNum, int goldenNum)
{
	int minNum = needNum[0];
	int minPersonNum = needNum[0];
	for (int i = 1; i < goldenNum; i++)
		if (needNum[i] < minNum) minNum = needNum[i];
	for (int i = 1; i < goldenNum; i++)
		minPersonNum += needNum[i];
	if (personNum < minNum || goldenNum < 1)
		return 0;
	else if (goldenNum == 1)
		return goldens[0];
	else
	{
		return MaxValue(DP_FindMaximumValue(personNum - needNum[goldenNum - 1], goldenNum - 1) + goldens[goldenNum - 1],
			DP_FindMaximumValue(personNum, goldenNum - 1));
	}
}

void main()
{
	int i;
	cout << DP_FindMaximumValue(9,3) << endl;
	cin >> i;
}

