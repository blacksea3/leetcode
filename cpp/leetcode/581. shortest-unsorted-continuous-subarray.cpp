#include "public.h"

//60ms, 35.79%
//排序一次然后查找左右边界

class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<int> sorted_nums = nums;
		sort(sorted_nums.begin(), sorted_nums.end());

		int leftloc = 0;
		while (leftloc < nums.size() && nums[leftloc] == sorted_nums[leftloc]) leftloc++;

		if (leftloc == nums.size()) return 0;

		int rightloc = nums.size() - 1;
		while (nums[rightloc] == sorted_nums[rightloc]) rightloc--;

		return rightloc - leftloc + 1;
	}
};
