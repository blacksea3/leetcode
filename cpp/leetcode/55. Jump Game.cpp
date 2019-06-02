#include "public.h"

//12ms, 98.13%

//greedy algorithm
//from back to front, when find the from one front loc can jump to the back loc, update the pre loc(back loc) using front loc

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int nsize = nums.size();
		if (nsize == 1) return true;

		int preloc = nsize - 1;
		for (int i = nsize - 2; i >= 0; i--)
		{
			if ((nums[i] + i) >= preloc) preloc = i;
		}
		return (preloc == 0);
	}
};
