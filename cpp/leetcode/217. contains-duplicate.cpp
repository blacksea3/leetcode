#include "public.h"

//48ms, 76.78%
//simple solution, set ШЅжи

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> us(nums.begin(), nums.end());
		return !(us.size() == nums.size());
	}
};
