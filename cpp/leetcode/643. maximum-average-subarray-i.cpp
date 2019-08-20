#include "public.h"

//268ms, 22.19%
//滑动窗口

class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int numSize = nums.size();
		int sum = accumulate(nums.begin(), nums.begin() + k, 0);
		int res = sum;

		//主滑动窗口
		for (int index = k; index < numSize; ++index)
		{
			sum += (nums[index] - nums[index - k]);
			res = max(res, sum);
		}

		return (double)res / (double)k;
	}
};
