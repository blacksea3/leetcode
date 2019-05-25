#include "public.h"

//4ms, 98.41%

//note that You can stores infos in nums
//and note that the res must <= nums.size() + 1

//So we can TRY TO move all positive values (x) to nums[x-1], then traverse nums to get the res firstMissingPositive

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int nsize = nums.size();

		int loc = 0;
		for (int i = 0; i < nsize; ++i)
		{
			while ((nums[i] != i + 1) && (nums[i] >= 1) && (nums[i] <= nsize) && (nums[i] != nums[nums[i] - 1]))
			{
				int temp = nums[nums[i] - 1];
				nums[nums[i] - 1] = nums[i];
				nums[i] = temp;
			}
		}
		for (int i = 0; i < nsize; i++) if (nums[i] != (i + 1)) return (i + 1);
		return nsize + 1;
	}
};
