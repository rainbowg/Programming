/*
LeetCode 22
给定n对括号，写一个函数去生成所有符合规则的括号组合
例子：
当n=3时，括号组合如下：
"((())), (()()), (())(), ()(()), ()()()"
解法思想：
利用递归，且保证字符串中的左括号>=右括号
*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;
vector<string> bracketSeq;
void GenerateBracketSequence(int lbrt, int rbrt, string str)
{
	//只有当作括号都没有了，且只剩一个右括号时才结束递归
	if (lbrt ==0 && rbrt == 1)
	{
		str += ')';
		bracketSeq.push_back(str);
		str.empty();
		return ;
	}
	else
	{
		if(lbrt!=0)
		{
			str += '(';
			lbrt -= 1;
			GenerateBracketSequence(lbrt, rbrt, str);
			//要把之前的操作逆转回去
			lbrt += 1;
			str.erase(str.length()-1);
		}
		if(rbrt>lbrt)
		{
			str += ')';
			rbrt -= 1;
			GenerateBracketSequence(lbrt, rbrt, str);
		}
	}
}


//int main()
//{
//	int i = 5;//次数
//	string str;
//	GenerateBracketSequence(i, i, str);
//
//	vector<string>::iterator it = bracketSeq.begin();
//	for (;it<bracketSeq.end();it++)
//	{
//		cout << (*it) << endl;
//	}
//	cin >> i;
//    return 0;
//}
