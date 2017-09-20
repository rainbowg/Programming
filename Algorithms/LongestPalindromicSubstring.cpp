#include <string>
#include <iostream>

using namespace std;
int LongestPalindromicSubstring(string str)
{
	int head = 0, cur = 0, pre = 0, length = 1, maxLength = 0;

	for (int i = 1; i < str.length(); i++)
	{
		//AA 
		if (i - 1 >= 0 && str[i] == str[i - 1])
		{
			length = 2;
			for (pre = i - 2, cur = i + 1; pre >= 0, cur < str.length();pre--, cur++)
			{
				if (str[cur] != str[pre])
					break;
				length += 2;
			}
			if (maxLength < length)
				maxLength = length;
			//当cur指向队尾时，退出循环
			if (cur == str.length())
				break;
		}
		//ABA
		if (i - 2 >= 0 && str[i] == str[i - 2])
		{
			length = 3;
			for (pre = i - 3, cur = i + 1; pre >= 0, cur < str.length();pre--, cur++)
			{
				if (str[cur] != str[pre])
					break;
				length += 2;
			}
			if (maxLength < length)
				maxLength = length;
			//当cur指向队尾时，退出循环
			if (cur == str.length())
				break;
		}
	}

	return maxLength;
}


//void main()
//{
//	string str = "abcbccbcba";
//	int tmp;
//	cout << LongestPalindromicSubstring(str);
//
//	cin >> tmp;
//}