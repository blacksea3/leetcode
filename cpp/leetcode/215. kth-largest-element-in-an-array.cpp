#include "public.h"

//12ms, 96.55%
//排序, 然后就可以了

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), greater<int>());
		return nums[k - 1];
	}
};

