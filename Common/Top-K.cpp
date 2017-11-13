/*
BFPRT算法过程：
1、选取主元
1.1、将n个元素划分为n/5个组，每组5个元素，若有剩余，舍去；
1.2、使用插入排序找到每组中的中位数
1.3、对1.2中找到的所有中位数，调用BFPRT算法求出他们的中位数（中位数的中位数），作为主元；
2、以1.3选取的主元为分界点，把小于主元的放在左边，大于主元的放在右边；
3、判断主元的位置与k的大小，有选择的对左边或右边递归


时间复杂度分析：
BFPRT算法在最坏情况下的时间复杂度是O(n)，下面予以证明。令T(n)为所求的时间复杂度，则有：
				T(n) <= T(n/5)+T(7n/10)+c*n  (c为一个正常数)
其中：
1、T(n/5)来自GetPiovtIndex()，n个元素，5个一组，共有(n/5)取下限个中位数；
2、T(7n/10)来自BFPRT()，在(n/5)取下限个中位数中，主元大于其中1/2 * n/5 = n/10的中位数，
而每个中位数在其本来的5个数的小组中有大于或等于其中的3个数，所有主元x至少大于所有数中的n/10 * 3 = 3n/10个。
即划分后，任意一边的长度至少为3/10，在最坏的情况下，每次选择都选择7/10的那一部分。
3、c*n来自其他操作，比如InsertSort()，以及GetPivotIndex()和Partition()里所需的一些额外操作。
*/

#include <iostream>
#include <algorithm>

using namespace std;

/*插入排序：返回中位数下标*/
int InsertSort(int array[], int left, int right)
{
	int temp;
	int j;

	for (int i = left + 1; i <= right; i++)
	{
		temp = array[i];
		j = i - 1;
		while (j >= left && array[j] > temp)
			array[j + 1] = array[j--];
		array[j + 1] = temp;
	}

	cout << "InsertSort from " << left << "to " << right << ": " << endl;
	for (int i = left; i <=right; i++)
		cout << array[i] << " ";
	cout << endl;

	return ((right - left) >> 1) + left;
}

int BFPRT(int array[], int left, int right, const int& k);

/*返回中位数的中位数下标*/
int GetPivotIndex(int array[], int left, int right)
{
	if (right - left < 5)
		return InsertSort(array, left, right);

	int sub_right = left - 1;

	for (int i = left; i + 4 <= right; i += 5) 
	{
		//找到5个元素的中位数下标，并依次放到左侧
		int index = InsertSort(array, i, i + 4);
		swap(array[++sub_right], array[index]);
	}

	cout << "new array:";
	for (int i = 0; i < 20; i++)
		cout << array[i] << " ";
	cout << endl;
	cout << "sub_right: " << sub_right << endl;

	return BFPRT(array, left, sub_right, ((sub_right - left + 1) >> 1) + 1);
}

/*利用中位数的中位数下标进行划分，返回分界线下标*/
int Partition(int array[], int left, int right, int pivot_index)
{
	//把主元放置末尾
	swap(array[pivot_index], array[right]);
	//跟踪划分的分界线
	int divide_index = left;

	for (int i = left; i < right; i++)
	{
		if (array[i] < array[right])
			// 比主元小的都放在左侧
			swap(array[divide_index++], array[i]);
	}
	//最后把主元换回来
	swap(array[divide_index], array[right]);

	cout << "Partition from " << left << "to " << right << ": " << endl;
	for (int i = left; i <= right; i++)
		cout << array[i] << " ";
	cout << endl;

	return divide_index;
}


int BFPRT(int array[], int left, int right, const int& k)
{
	//得到中位数的中位数下标
	int pivot_index = GetPivotIndex(array, left, right);
	cout << "pivot_index: " << pivot_index << "; value: " << array[pivot_index] << endl;
	//进行划分，返回划分边界
	int divide_index = Partition(array, left, right, pivot_index);
	cout << "divide_index: " << divide_index << "; value: " << array[divide_index] << endl;
	int num = divide_index - left + 1;
	cout << "num: " << num << "; k: " << k << endl;
	
	if (num == k)
		return divide_index;
	else if (num > k)
		return BFPRT(array, left, divide_index - 1, k);
	else
		return BFPRT(array, divide_index + 1, right, k - num);
}

//int main()
//{
//	cout << ((19 - 0) >> 1) << endl;
//	int k = 8;
//	int array[20] = {1,2,3,1,5,-1,7,8,-10,8,2,6,11,33,25,-17,-19,20,21,-22 };
//
//	cout << "old array:";
//	for (int i = 0; i < 20; i++)
//		cout << array[i] << " ";
//	cout << endl;
//
//	cout << "the" << k << "th:" << array[BFPRT(array, 0, 19, k)] << endl;
//
//	cout << "new array:";
//	for (int i = 0; i < 20; i++)
//		cout << array[i] << " ";
//	cout << endl;
//	cin >> k;
//	return 0;
//}