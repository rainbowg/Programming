/*
FB-等差子序列

给定一整数数列，问数列有多少个子序列是等差数列。
即对于包含N个数的数列A，A(0),A(1),……,A(N-1)，有多少组（P(0),P(1),……,P(k)）满足0<=P(0)<P(1)<……<P(k)<N，且A(P(0)),A(P(1)),……,A(P(k))为等差数列。
等差数列至少包含3个数，故必有k>=2，同时等差数列相邻两个数的差都是一样的，即A(P(1))-A(P(0) = A(P(2))-A(P(1)) = …… = A(P(k))-A(P(k-1)) = d，d被称为公差。
输入保证N个整数的取值范围均为-2^31 ~ 2^31-1，并且0<=N<=1000，同时保证输出小于2^31-1。
样例
输入: [2, 4, 6, 8, 10]
输出: 7
说明:所有等差子序列为:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
*/
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> ArithmeticProgression(vector<int> seq)
{
	vector<vector<int>> arithPro;
	vector<int>::iterator fst, sec, trd;
	int commonDiff = 0, preNum;

	vector<int> tmpSeq;

	for (fst = seq.begin();fst < seq.end();fst++)
	{
		for (sec = fst + 1;sec < seq.end();sec++)
		{
			tmpSeq.push_back((*fst));
			tmpSeq.push_back((*sec));
			commonDiff = (*sec) - (*fst);
			preNum = (*sec);
			for (trd = sec + 1;trd < seq.end();trd++)
			{
				if ((*trd) == preNum + commonDiff)
				{
					tmpSeq.push_back((*trd));
					if (tmpSeq.size() > 2)
						arithPro.push_back(tmpSeq);
					preNum = (*trd);
				}
			}
			/*if (tmpSeq.size() > 2)
				arithPro.push_back(tmpSeq);*/
			tmpSeq.clear();
		}
	}

	return arithPro;
}
//
//void main()
//{
//	vector<vector<int>> arithPro = ArithmeticProgression({ 2,3,4,5,6,8,10 });
//	vector<vector<int>>::iterator fstLevel;
//	vector<int>::iterator secLevel;
//
//	for (fstLevel = arithPro.begin();fstLevel < arithPro.end();fstLevel++)
//	{
//		for (secLevel = (*fstLevel).begin(); secLevel < (*fstLevel).end();secLevel++)
//		{
//			cout << (*secLevel) << " ";
//		}
//		cout << endl;
//	}
//
//	system("pause");
//}