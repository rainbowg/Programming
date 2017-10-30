/*
查找最小的k个元素（数组）
题目：输入n个整数，输出其中最小的k个。
例如输入1，2，3，4，5，6，7和8这8个数字，则最小的4个数字为1，2，3和4
解题思路：
1、当输入数据大于内存容量时，可以分批处理。找出每批中最小的K个元素，再汇总，得出最后的最小K个元素（如归并排序）
2、当输入数据在一定范围内且不重复可以用bitmap实现，即对于的位置是否为1，表示该值是否出现。然后在bitmap中最最左端的K个为1的元素
3、快速排序实现方式。选择输入中的任意一个数，找
4、最小堆输出k个值
5、BFPRT算法（O(n)）
*/
#include <stdio.h>
#include <stdlib.h>

int Partition(int* arr, int start, int end)
{
	int pivot = arr[start], tmp;
	while (start < end)
	{
		while (start < end && arr[end] > pivot) end--;
		while (start < end && arr[start] < pivot) start++;
		tmp = arr[end];
		arr[end] = arr[start];
		arr[start] = tmp;
	}

	return start;
}

int* MinK(int* arr, int start, int end, int k)
{
	if (k > end + 1)
		return NULL;
	if (k == end + 1)
	{
		return arr;
	}
	if (start <= end)
	{
		int pos = Partition(arr, start, end);
		if (pos == k - 1 )
			return arr;
		else if (pos > k - 1)
		{
			MinK(arr, start, pos - 1, k);
		}
		else
		{
			MinK(arr, pos + 1, end, k - pos);
		}
	}
}

//void main()
//{
//	int arr[] = { 7,3,2,1,5,6,4 };
//	int k = 3;
//	MinK(arr, 0, 6, k);
//
//	for (int i = 0;i < k;i++)
//		printf("%d,",arr[i]);
//
//	getchar();
//}

