#include "public.h"

//44ms, 83.32%
//…Ë÷√map

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> um;
		for (int i = 0; i < nums.size(); i++)
		{
			if (um.find(nums[i]) == um.end())
				um[nums[i]] = i;
			else
				if ((i - um[nums[i]]) <= k) return true;
				else um[nums[i]] = i;
		}
		return false;
	}
};
