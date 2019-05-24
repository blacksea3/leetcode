#include "public.h"

//32ms, 96.27%

//only need one traverse

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int nsize = nums.size();
		if (nsize == 0) return 0;   //special input
		int preloc = 0;
		int old_num = nums[0] + 1;    //dump init value, only different from nums[0]
		for (auto num:nums)
		{
			if (num != old_num)
			{
				old_num = num;
				nums[preloc++] = num;
			}
		}
		return preloc;
	}
};
