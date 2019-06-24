#include "public.h"

//4ms, 88.46%
//simple solution

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		if (nums.size() == 0) return {};

		int prestart = nums[0];
		int preend = nums[0];
		vector<string> res;
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] != ++preend)
			{
				if ((preend - prestart) == 1)
					res.push_back(to_string(prestart));
				else
					res.push_back(to_string(prestart) + "->" + to_string(preend - 1));
				prestart = nums[i];
				preend = nums[i];
			}
		}
		if (preend == prestart)
			res.push_back(to_string(prestart));
		else
			res.push_back(to_string(prestart) + "->" + to_string(preend));
		return res;
	}
};
