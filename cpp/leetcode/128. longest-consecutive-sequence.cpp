#include "public.h"

//12ms, 92.67%
//思路:对nums去重放入unordered_set
//对每个nums里面的数字,在unordered_set里面查找连续的比它小的/连续的比它大的(扩展边界)
//同时对于查到的数字都从unordered_set里面去掉,
//然后更新答案

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> us(nums.begin(), nums.end());
		int res = 0;
		for (auto& num : nums)
		{
			if (!us.count(num)) continue;
			us.erase(num);
			int left = num - 1;
			while (us.find(left) != us.end()) us.erase(left--);
			int right = num + 1;
			while (us.find(right) != us.end()) us.erase(right++);
			res = max(res, right - left - 1);
		}
		return res;
	}
};
