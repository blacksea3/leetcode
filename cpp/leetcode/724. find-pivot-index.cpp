#include "public.h"

//24ms, 96.77%
//“ª±È…®√Ë

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		if (nums.empty()) return -1;

		int leftSum = 0;
		int rightSum = accumulate(nums.begin() + 1, nums.end(), 0);

		if (leftSum == rightSum) return 0;
		else
		{
			for (int index = 1; index < nums.size(); ++index)
			{
				leftSum += nums[index - 1];
				rightSum -= nums[index];
				if (leftSum == rightSum)
					return index;
			}
			return -1;
		}
	}
};
