#include "public.h"

/*
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
*/

//4ms, 96.72%
//DP+二分
//维持一个有序变长DP序列: 内部已排序, 长度表示当前最长上升子序列(但内容却不一定完全合法)
//对每个新的num, 如果当前插入DP位置在末尾则DP长度+1,并插入, 否则替换掉可以插入的位置
//最终返回DP的长度

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp;

		for (auto& num : nums)
		{
			vector<int>::iterator iter = lower_bound(dp.begin(), dp.end(), num);
			if (iter == dp.end()) dp.emplace_back(num);
			else dp[iter - dp.begin()] = num;
		}
		return dp.size();
	}
};
