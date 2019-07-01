#include "public.h"

//20ms, 91.39%
//simple solution

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int loc = 0;
		for (auto num : nums)
		{
			if (num) nums[loc++] = num;
		}

		for (int i = loc; i < nums.size(); ++i)
			nums[i] = 0;

	}
};
