/*
5�����10���ˡ�ÿ�����Ҫôȫ�ڣ�Ҫô���ڡ�
����ܹ���ȡ���Ļƽ�
5��������£�500��/5�ˣ�200��/3�ˣ�300��/4�ˣ�350��/3�ˣ�400��/5��


�ݹ�棨�������£���
1) ������С��������������ʱ������0��
2) �������������1����ֱ�ӷ��ؽ����
3) �ݹ����㣨��̬�滮������g[n]Ϊ�������p[n]Ϊ�����������,
f[i][j]Ϊ������Ϊi�����Ϊjʱ��������mΪ��������
   Max(g[n] + f[m-p[n]][n-1], g[m][n-1])

����¼�棨�������ϣ���
1) ����߽�ֵ
2) ѭ���������ֵ
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

