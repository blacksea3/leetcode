#include "public.h"

//注意都是正整数, 而且没有重复数字!, 给定也是正整数!
//dp[i] i时的组合个数
//那么dp[大数字]=nums中的各个数+dp[小数字]

//注意这个输入:nums={3,33,333}, target =10000, 结果是0, 但是直接算会溢出, 所以有dp[i]>INT_MAX一项

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<long> dp(target + 1, 0);
		//初始化dp[0]=1
		dp[0] = 1;
		for (int i = 1; i <= target; ++i)
		{
			for (auto& n : nums)
				if (i - n >= 0)
				{
					dp[i] += dp[i - n];
					if (dp[i] > INT_MAX) break;
				}
		}
		return dp[target];
	}
};

