/*
295. Find Median from Data Stream
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. 
So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3
[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:
void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.

For example:
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2
�ⷨһ��
����һ�����飬ÿ�ε���addNumʱ���ø�������������Ȼ�����ҳ���λ�����÷���ʱ�临�Ӷ���O(N),NΪ���鳤�ȣ�ʱ�������������ϣ�
�ⷨ����
������С�ѣ��ڵ���addNumʱ������Ҫά���ѵĽṹ��ͬʱ��Ҫ��֤�����ѵĴ�С������Ϊ1���÷�����ʱ�临�Ӷ�ΪO(lgN)��ʱ�������ڶѵ�ά���ϣ�
��������ֳ��������֣������һ�����ѣ��ұ���һ����С�ѡ�
*/


#include <cstddef>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

class MedianFinder 
{
public:
	/** initialize your data structure here. */
	MedianFinder() 
	{
	}

	void addNum(int num)
	{
		if (m_min.size() != 0 && num < m_min[0])
		{
			m_max.push_back(num);
			push_heap(m_max.begin(), m_max.end());

			if (m_max.size() > m_min.size() + 1)
			{
				pop_heap(m_max.begin(), m_max.end());
				int maxVal = m_max[m_max.size() - 1];
				m_max.pop_back();
				m_min.push_back(maxVal);
				push_heap(m_min.begin(), m_min.end(), greater<int>());
			}
		}
		else
		{
			m_min.push_back(num);
			push_heap(m_min.begin(), m_min.end(), greater<int>());
			if (m_min.size() > m_max.size())
			{
				pop_heap(m_min.begin(), m_min.end(), greater<int>());
				int maxVal = m_min[m_min.size() - 1];
				m_min.pop_back();
				m_max.push_back(maxVal);
				push_heap(m_max.begin(), m_max.end());
			}
		}
	}

	double findMedian()
	{
		if ((m_max.size() + m_min.size()) % 2 == 0)
			return (m_max[0] + m_min[0]) / 2.0;
		else
			return m_max[0];
	}
private:
	
private:
	vector<int> m_min;
	vector<int> m_max;
};


//void main()
//{
//	int i;
//	MedianFinder *obj = new MedianFinder();
//	obj->addNum(1);
//	obj->addNum(2);
//	cout << obj->findMedian() << endl;
//	obj->addNum(3);
//	cout << obj->findMedian() << endl;
//	obj->addNum(4);
//	cout << obj->findMedian() << endl;
//
//	obj->addNum(5);
//	cout << obj->findMedian() << endl;
//	obj->addNum(6);
//	cout << obj->findMedian() << endl;
//	cin >> i;
//}
/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder obj = new MedianFinder();
* obj.addNum(num);
* double param_2 = obj.findMedian();
*/