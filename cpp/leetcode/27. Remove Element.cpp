#include "public.h"

//4ms, 98.93%

//only need one traverse

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int nsize = nums.size();
		if (nsize == 0) return 0;  //special input
		int pre_loc = 0;

		for (auto num:nums)
		{
			if (num != val) nums[pre_loc++] = num;
		}
		return pre_loc;
	}
};