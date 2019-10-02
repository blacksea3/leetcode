#include "public.h"

//44ms, 71.18%
//DP problem
//O(n^2), 理论上可以结合二分查找降至O(nlongn), 待优化
//对于某个位置, dp[i]表示到这里的最长上升子序列长度
//更新dp[i+1]时遍历前面的所有dp, 并且比较两个数字

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int nSize = nums.size();

		if (nSize == 0) return 0;
		else
		{
			vector<int> dp(nSize, 0);
			dp[0] = 1;

			for (int i = 1; i < nSize; ++i)
			{
				int premax = 0;
				for (int j = 0; j < i; ++j)
				{
					if (nums[j] < nums[i]) premax = max(premax, dp[j]);
				}
				dp[i] = premax + 1;
			}
			return *max_element(dp.begin(), dp.end());
		}
	}
};
