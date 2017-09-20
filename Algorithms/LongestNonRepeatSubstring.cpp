/*
LeetCode 3
����һ���ַ�����Ѱ��û���ַ��ظ�������ַ�����
���ӣ�
�����ַ�����"abcdoi234567aedcabcdefgqwertyuiop"
�����abcdefgqwertyuiop
�ⷨ˼�룺
ѭ��Ƕ��
*/
#include <string>
#include <iostream>

using namespace std;

int LongestNonRepeatSubstring(string str)
{
	int head = 0, cur = 0, length = 1, maxLength = 0;

	for (int i = 1; i < str.length(); i++)
	{
		length = 1;
		for (int j = head; j < i; j++)
		{
			if (str[j] != str[i])
				length++;
			else
			{
				head = i;
				break;
			}
			if (maxLength < length)
			{
				maxLength = length;
			}
		}
	}

	return maxLength;
}


//void main()
//{
//	string str = "abcdoi234567aedcabcdefgqwertyuiop";
//	int tmp;
//	cout << LongestNonRepeatSubstring(str);
//
//	cin >> tmp;
//}