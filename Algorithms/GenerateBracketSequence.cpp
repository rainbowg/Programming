/*
LeetCode 22
����n�����ţ�дһ������ȥ�������з��Ϲ�����������
���ӣ�
��n=3ʱ������������£�
"((())), (()()), (())(), ()(()), ()()()"
�ⷨ˼�룺
���õݹ飬�ұ�֤�ַ����е�������>=������
*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;
vector<string> bracketSeq;
void GenerateBracketSequence(int lbrt, int rbrt, string str)
{
	//ֻ�е������Ŷ�û���ˣ���ֻʣһ��������ʱ�Ž����ݹ�
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
			//Ҫ��֮ǰ�Ĳ�����ת��ȥ
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
//	int i = 5;//����
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
