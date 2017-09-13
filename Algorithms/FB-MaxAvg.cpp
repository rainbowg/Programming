/*
Facebook 最大平均子数组
lintcode(617)

例子：
输入：[1, 2, 3, 2, -10, 1，8，0], k=2
输出：4.5,[1,8]

输入：[1, 2, 3, 2, -10, 1，8，0], k=3
输出：3,[1,8,0]

输入：[1, 2, 3, 2, -10, 1，8，0], k=4
输出：2,[1,2,3,2]

由此可以看出k=4时的数据并不包含k=3的数据；

思路：
http://blog.csdn.net/sunday0904/article/details/70172058
1.一组数的平均值一定在这组数中的最大值和最小值之间。
min<=average<=max;
这组数的子数组的平均值也一定在这个范围内。
2.利用这一性质，首先求解最大值和最小值并求出它们的平均数mid。
3.用search函数判断至少k个长度的子数组的平均值与mid的大小。
search函数中计算了每一个值与mid的差，也就是和平均数之间的偏差，并依次累加求和，存贮在sum[]中。
然后比较偏差的变化，在子数组长度大于等于k之后，开始比较当前偏差之和与k个元素之前的所有偏差的最小值（以后简称最小值），如果当前偏差之和大于最小值，说明子数组的平均数被增大了，也就说明存在某一子数组的平均值大于mid，所以返回true，这样low=mid；如果遍历到最后发现偏差的和始终小于最小值，说明所有子数组的平均值，都小于mid，所以返回false，这样high=mid。
上述子数组的长度均要求大于等于k，不再强调。
所以类似于二分法，不断地确定子数组最大平均数的范围，直至high=low。
*/

#include <vector>
#include <iostream>

using namespace std;
const unsigned int MAX_UINT = 0xffffffff;
const int  MAX_INT = 0x7fffffff;
const int  MIN_INT = 0x80000000;

class Solution {
private:
	double search(vector<int>&nums, int k, double mid) 
	{
		double min = 0;
		vector<double> sum(nums.size()+1);
		sum[0] = 0;

		for (int i = 1;i <= nums.size(); i++)
		{
			sum[i] = sum[i - 1] + nums[i - 1] - mid;
			if (i > k && sum[i] >= min)
				return true;
			if (i >= k)
				min = min < sum[i - k + 1] ? min : sum[i - k + 1];
		}

		return false;
	}
public:
	double maxAverage(vector<int>& nums, int k) 
	{
		double maxVal = numeric_limits<double>::min();
		double minVal = numeric_limits<double>::max();
		double midVal = 0.0;

		for (int i = 0;i < nums.size();i++)
		{
			if (maxVal < nums[i])
				maxVal = nums[i];
			if (minVal > nums[i])
				minVal = nums[i];
		}

		while (maxVal - minVal >= 1e-6)
		{
			midVal = (maxVal + minVal) / 2.0;
			if (search(nums, k, midVal))
				minVal = midVal;
			else
				maxVal = midVal;
		}

		return maxVal;
	}
};

//
//void main()
//{
//	Solution* sl = new Solution();
//	vector<int> nums = { 1, 12, -5, -6, 50, 3 };
//	cout << sl->maxAverage(nums, 3);
//
//	system("pause");
//}