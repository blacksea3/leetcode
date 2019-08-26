#include "public.h"

//140ms, 5.39%
//找出最大的三个正的以及最小的两个负的
//结果等于三个正的之积与最大的正的与两个最小的负的之积
//简化: 直接找最大的三个数和最小的两个数, 然后比较就行
//为简化代码, 直接sort

class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		return max(nums[0] * nums[1] * nums[nums.size() - 1],
			nums[nums.size() - 3] * nums[nums.size() - 2] * nums[nums.size() - 1]);
	}
};
