#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef vector<pair<int, int>> vtint;
int FB_StickBallon(vtint vt)
{
	int count = 0;
	vtint::const_iterator it, iter;
	for (it = vt.cbegin(); it < vt.cend();)
	{
		count++;
		for (iter = it+1; iter < vt.cend();)
		{
			if ((*iter).first <= (*it).second && (*iter).second >= (*it).second)
				iter = vt.erase(iter);
			else
				iter++;
		}
		it = vt.erase(it);
	}
	
	return count;
}

bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
	return i.second < j.second;
}

//void main()
//{
//	vtint vt; int i;
//	vt.push_back(make_pair(10,16));
//	vt.push_back(make_pair(2, 8));
//	vt.push_back(make_pair(1, 6));
//	vt.push_back(make_pair(7, 12));
//
//	vtint::const_iterator it;
//	for (it = vt.cbegin(); it < vt.cend(); it++)
//		cout << (*it).first << "," << (*it).second << endl;
//	sort(vt.begin(), vt.end(), compare);
//	for (it = vt.cbegin(); it < vt.cend(); it++)
//		cout << (*it).first << "," << (*it).second << endl;
//
//	cout << FB_StickBallon(vt);
//	cin >> i;
//}