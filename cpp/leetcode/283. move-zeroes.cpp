#include "public.h"

//12ms, 99.60%
//按规则, 设置下标指针

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int loc = 0;
		for (auto& num : nums)
		{
			if (num) nums[loc++] = num;
		}

		for (int i = loc; i < nums.size(); ++i)
			nums[i] = 0;
	}
};
