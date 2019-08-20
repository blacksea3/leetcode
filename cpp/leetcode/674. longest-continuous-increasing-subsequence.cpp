#include "public.h"

//28ms, 15.32%
//“ª±È…®√Ë

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		if (nums.empty()) return 0;

		int resMaxLen = 1;
		int preLen = 1;

		for (int index = 1; index < nums.size(); ++index)
		{
			if (nums[index] > nums[index - 1])
			{
				preLen++;
			}
			else
			{
				resMaxLen = max(resMaxLen, preLen);
				preLen = 1;
			}
		}
		return max(resMaxLen, preLen);
	}
};
