/*
Google �ֻ�
����flowerbed��һ������0��1�����飬0��ʾ�û���Ϊ�գ�1��ʾ�û����Ѿ����˻���
�Լ�һ����n�����Ƿ�����������µ�n�껨���������ڻ��۲���ͬʱ�ֻ���������

���ӣ�
���룺flowerbed=[1,0,0,0,1], n=1
�����ture

���룺flowerbed=[1,0,0,0,1], n=2
�����false

����˼·��̰���㷨
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