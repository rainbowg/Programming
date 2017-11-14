/*
��Ҫ���
ǰ׺���������һ���ַ����⣬һ���ַ�����ȫ��ͷ����ϣ�
��׺�����˵�һ���ַ����⣬һ���ַ�����ȫ��β����ϣ�
���ַ�������bread��
ǰ׺��b, br, bre, brea
��׺��read, ead, ad, d

����ƥ��ֵ������ǰ׺�ͺ�׺����Ĺ���Ԫ�صĳ��ȣ�
�ԡ�ABCDABD��Ϊ����
- ��A����ǰ��׺��Ϊ�ռ�������Ԫ�صĳ���Ϊ0��
- ��AB����ǰ׺Ϊ[A]����׺Ϊ[B]������Ԫ�س���Ϊ0��
- ...
- ��ABCDAB����ǰ׺Ϊ[A, AB, ABC, ABCD, ABCDA]����׺Ϊ[BCDAB, CDAB, DAB, AB, B]������Ԫ��Ϊ��AB��������Ϊ2��
- ...
������ƥ�䡱��ʵ�����ַ���ͷ����β������ʱ�򣩻����ظ���

next����������Ϊ��ͨ�������ͬǰ��׺����ֵ����һλ��Ȼ���ʼֵ��Ϊ-1��

�Ż�next���飺�����ַ�����ABAB����next����Ϊ��-1��0��0��1�������������롰ABACABABC������ƥ��ʱ����B���͡�C��ƥ��ʧ�ܣ�
����next��������1��λ�ã�Ҳ���ַ���B��������Ȼʧ�䡣


KMP�㷨ʱ�������
���Ƿ������ĳ���ַ�ƥ��ɹ���ģʽ�����ַ���λ�ñ��ֲ��������ƥ��ʧ�ܣ�ģʽ��������next[j]���ַ��������㷨���
������ǣ���ģʽ���׸��ַ�λ��n-m��λ�ò�ƥ��ɹ����㷨������
���ԣ�����ı�������Ϊn��ģʽ������Ϊm����ôƥ�����ʱ�临�Ӷ�ΪO(n)�����ϼ���next�����ʱ��O(m)��KMP����ΪO(n+m)

*/

#include <iostream>
#include <vector>

using namespace std;

void GetNext(char* temp, int* next)
{
	next[0] = -1;
	int pre = -1, post = 0;

	while (post < strlen(temp))
	{
		if (pre == -1 || temp[pre] == temp[post])
		{
			++pre;
			++post;
			// ԭʼ����
			next[post] = pre;

			// �Ż�Next����
			/*if (temp[pre] != temp[post])
				next[post] = pre;
			else
				next[post] = next[pre];*/
		}
		else
			pre = next[pre];
	}
}

int KMPSearch(char* temp, char* array, int* next)
{
	int pos = -1;
	int pArray = 0, pTemp = 0;
	int lenTemp = strlen(temp), lenArray = strlen(array);
	while (pTemp < lenTemp && pArray < lenArray)
	{
		if (pTemp == -1 || array[pArray] == temp[pTemp])
		{
			pArray++;pTemp++;
		}
		else
		{
			pTemp = next[pTemp];
		}

	}

	if (pTemp == strlen(temp))
		pos = pArray - pTemp;

	return pos;
}

//int main()
//{
//	char temp[] = "ABCDABCE"; 
//	char array[] = "BBC ABCEABCDABD ABCDABCEAB";
//	int next[8] = { 0 };
//	int i;
//	GetNext(temp, next);
//	if (-1 < 8)
//		cout << "true" << endl;
//	for (int i = 0; i < strlen(temp); i++)
//	{
//		cout << next[i] << " ";
//	}
//
//	cout << endl << "find pos:��" << KMPSearch(temp, array, next);
//
//	cin >> i;
//	/*system("pause");*/
//}



































