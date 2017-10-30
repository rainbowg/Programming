/*
������С��k��Ԫ�أ����飩
��Ŀ������n�����������������С��k����
��������1��2��3��4��5��6��7��8��8�����֣�����С��4������Ϊ1��2��3��4
����˼·��
1�����������ݴ����ڴ�����ʱ�����Է��������ҳ�ÿ������С��K��Ԫ�أ��ٻ��ܣ��ó�������СK��Ԫ�أ���鲢����
2��������������һ����Χ���Ҳ��ظ�������bitmapʵ�֣������ڵ�λ���Ƿ�Ϊ1����ʾ��ֵ�Ƿ���֡�Ȼ����bitmap��������˵�K��Ϊ1��Ԫ��
3����������ʵ�ַ�ʽ��ѡ�������е�����һ��������
4����С�����k��ֵ
5��BFPRT�㷨��O(n)��
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

