#include "public.h"

//
//ÊıÊı

class Solution {
public:
	bool isMajorityElement(vector<int>& nums, int target) {
		int precount = 0;

		for (auto& n : nums) if (n == target) precount++;

		if (precount > ((int)nums.size() / 2)) return true;
		else return false;
	}
};
