/*
Facebook ���ƽ��������
lintcode(617)

���ӣ�
���룺[1, 2, 3, 2, -10, 1��8��0], k=2
�����4.5,[1,8]

���룺[1, 2, 3, 2, -10, 1��8��0], k=3
�����3,[1,8,0]

���룺[1, 2, 3, 2, -10, 1��8��0], k=4
�����2,[1,2,3,2]

�ɴ˿��Կ���k=4ʱ�����ݲ�������k=3�����ݣ�

˼·��
http://blog.csdn.net/sunday0904/article/details/70172058
1.һ������ƽ��ֵһ�����������е����ֵ����Сֵ֮�䡣
min<=average<=max;
���������������ƽ��ֵҲһ���������Χ�ڡ�
2.������һ���ʣ�����������ֵ����Сֵ��������ǵ�ƽ����mid��
3.��search�����ж�����k�����ȵ��������ƽ��ֵ��mid�Ĵ�С��
search�����м�����ÿһ��ֵ��mid�ĲҲ���Ǻ�ƽ����֮���ƫ��������ۼ���ͣ�������sum[]�С�
Ȼ��Ƚ�ƫ��ı仯���������鳤�ȴ��ڵ���k֮�󣬿�ʼ�Ƚϵ�ǰƫ��֮����k��Ԫ��֮ǰ������ƫ�����Сֵ���Ժ�����Сֵ���������ǰƫ��֮�ʹ�����Сֵ��˵���������ƽ�����������ˣ�Ҳ��˵������ĳһ�������ƽ��ֵ����mid�����Է���true������low=mid����������������ƫ��ĺ�ʼ��С����Сֵ��˵�������������ƽ��ֵ����С��mid�����Է���false������high=mid��
����������ĳ��Ⱦ�Ҫ����ڵ���k������ǿ����
���������ڶ��ַ������ϵ�ȷ�����������ƽ�����ķ�Χ��ֱ��high=low��
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