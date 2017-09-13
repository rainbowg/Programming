/*
FB-�Ȳ�������

����һ�������У��������ж��ٸ��������ǵȲ����С�
�����ڰ���N����������A��A(0),A(1),����,A(N-1)���ж����飨P(0),P(1),����,P(k)������0<=P(0)<P(1)<����<P(k)<N����A(P(0)),A(P(1)),����,A(P(k))Ϊ�Ȳ����С�
�Ȳ��������ٰ���3�������ʱ���k>=2��ͬʱ�Ȳ����������������Ĳ��һ���ģ���A(P(1))-A(P(0) = A(P(2))-A(P(1)) = ���� = A(P(k))-A(P(k-1)) = d��d����Ϊ���
���뱣֤N��������ȡֵ��Χ��Ϊ-2^31 ~ 2^31-1������0<=N<=1000��ͬʱ��֤���С��2^31-1��
����
����: [2, 4, 6, 8, 10]
���: 7
˵��:���еȲ�������Ϊ:
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