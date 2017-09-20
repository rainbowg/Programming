/*
LeetCode 3
给定一个字符串，寻找没有字符重复的最长子字符串。
例子：
给定字符串："abcdoi234567aedcabcdefgqwertyuiop"
输出：abcdefgqwertyuiop
解法思想：
循环嵌套
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