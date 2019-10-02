#include "public.h"

//36ms, 89.43%
//setÈ¥ÖØ

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> us(nums.begin(), nums.end());
		return !(us.size() == nums.size());
	}
};
