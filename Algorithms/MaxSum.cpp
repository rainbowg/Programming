/*
求子数组的最大和（数组）
题目：
输入一个整形数组，数组里有正数也有负数。
数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和。
求所有子数组的和的最大值。要求时间复杂度为O(n)。
例如输入的数组为1, -2, 3, 10, -4, 7, 2, -5，和最大的子数组为3, 10, -4, 7, 2，
因此输出为该子数组的和18。

如果题目要求把子数组输出的话，还需增加变量，用来存储起始位置和终止位置或长度
*/
#include<stdio.h>

int MaxSum(int arr[], int len)
{
	if (arr == NULL)
		return -1;
	int max = 0;
	int startPos = -1;
	int size = 0;
	for (int i = 0;i < len;i++)
	{
		if (max + arr[i] < 0)
		{
			max = 0;
		}
		else
		{
			if (max + arr[i] > max)
				max = max + arr[i];
			if (startPos == -1)
				startPos = i;
			else
				size++;
		}
	}
}