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
解法一：
建立一个数组，每次调用addNum时，让该数组重新排序，然后再找出中位数。该方法时间复杂度是O(N),N为数组长度，时间消耗在排序上；
解法二：
建立大小堆，在调用addNum时，不仅要维护堆的结构，同时还要保证两个堆的大小最多相差为1。该方法的时间复杂度为O(lgN)，时间消耗在堆的维护上；
整个数组分成两个部分，左边是一个最大堆，右边是一个最小堆。
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