#include "public.h"

//20ms, 45.31%
//dp[i] 表示凑成i的硬币组合数
//初始化dp[0] = 1
//递推, 按硬币金额递推, 子循环按金额递推, 大的金额dp[i + n] += 小的金额dp[i], n为当前金额
//注意:对于某种组合多个相同硬币, 全部在某一个子循环中求解
//另外:因为是按硬币金额递推循环的, 不存在重复计算问题
//返回dp[amount]

class Solution {
public:
	int change(int amount, vector<int>& coins) {
		vector<int> dp(amount + 1, 0);
		dp[0] = 1;

		for (auto& coin : coins)
		{
			for (int val = coin; val <= amount; ++val)
			{
				dp[val] += dp[val - coin];
			}
		}
		return dp[amount];
	}
};
