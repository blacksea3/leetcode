#include "public.h"

//68ms, 44.67%
//DP problem
//O(n^2)
//对于某个位置, dp[i]表示到这里的最长上升子序列长度
//更新dp[i+1]时遍历前面的所有dp, 并且比较两个数字

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		else
		{
			vector<int> dp(nums.size(), 0);
			dp[0] = 1;

			for (int i = 1; i < nums.size(); ++i)
			{
				int premax = 0;
				for (int j = 0; j < i; ++j)
				{
					if (nums[j] < nums[i]) premax = max(premax, dp[j]);
				}
				dp[i] = premax + 1;
			}
			int res = 0;
			for (int i = 0; i < nums.size(); ++i) res = max(dp[i], res);
			return res;
		}
	}
};
