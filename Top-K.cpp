/*
BFPRT�㷨���̣�
1��ѡȡ��Ԫ
1.1����n��Ԫ�ػ���Ϊn/5���飬ÿ��5��Ԫ�أ�����ʣ�࣬��ȥ��
1.2��ʹ�ò��������ҵ�ÿ���е���λ��
1.3����1.2���ҵ���������λ��������BFPRT�㷨������ǵ���λ������λ������λ��������Ϊ��Ԫ��
2����1.3ѡȡ����ԪΪ�ֽ�㣬��С����Ԫ�ķ�����ߣ�������Ԫ�ķ����ұߣ�
3���ж���Ԫ��λ����k�Ĵ�С����ѡ��Ķ���߻��ұߵݹ�


ʱ�临�Ӷȷ�����
BFPRT�㷨�������µ�ʱ�临�Ӷ���O(n)����������֤������T(n)Ϊ�����ʱ�临�Ӷȣ����У�
				T(n) <= T(n/5)+T(7n/10)+c*n  (cΪһ��������)
���У�
1��T(n/5)����GetPiovtIndex()��n��Ԫ�أ�5��һ�飬����(n/5)ȡ���޸���λ����
2��T(7n/10)����BFPRT()����(n/5)ȡ���޸���λ���У���Ԫ��������1/2 * n/5 = n/10����λ����
��ÿ����λ�����䱾����5������С�����д��ڻ�������е�3������������Ԫx���ٴ����������е�n/10 * 3 = 3n/10����
�����ֺ�����һ�ߵĳ�������Ϊ3/10�����������£�ÿ��ѡ��ѡ��7/10����һ���֡�
3��c*n������������������InsertSort()���Լ�GetPivotIndex()��Partition()�������һЩ���������
*/

#include <iostream>
#include <algorithm>

using namespace std;

/*�������򣺷�����λ���±�*/
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

/*������λ������λ���±�*/
int GetPivotIndex(int array[], int left, int right)
{
	if (right - left < 5)
		return InsertSort(array, left, right);

	int sub_right = left - 1;

	for (int i = left; i + 4 <= right; i += 5) 
	{
		//�ҵ�5��Ԫ�ص���λ���±꣬�����ηŵ����
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

/*������λ������λ���±���л��֣����طֽ����±�*/
int Partition(int array[], int left, int right, int pivot_index)
{
	//����Ԫ����ĩβ
	swap(array[pivot_index], array[right]);
	//���ٻ��ֵķֽ���
	int divide_index = left;

	for (int i = left; i < right; i++)
	{
		if (array[i] < array[right])
			// ����ԪС�Ķ��������
			swap(array[divide_index++], array[i]);
	}
	//������Ԫ������
	swap(array[divide_index], array[right]);

	cout << "Partition from " << left << "to " << right << ": " << endl;
	for (int i = left; i <= right; i++)
		cout << array[i] << " ";
	cout << endl;

	return divide_index;
}


int BFPRT(int array[], int left, int right, const int& k)
{
	//�õ���λ������λ���±�
	int pivot_index = GetPivotIndex(array, left, right);
	cout << "pivot_index: " << pivot_index << "; value: " << array[pivot_index] << endl;
	//���л��֣����ػ��ֱ߽�
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