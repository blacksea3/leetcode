#include "public.h"

//56ms, 32.35%
//ÊýÊý

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int premax = 0;
		int resmax = 0;

		for (auto& num : nums)
		{
			if (num) premax++;
			else
			{
				resmax = max(resmax, premax);
				premax = 0;
			}
		}
		return max(resmax, premax);
	}
};
