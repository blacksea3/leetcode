#include "public.h"

//84ms, 87.87%
//sort

class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums;
	}
};