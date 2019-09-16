#include "public.h"

//12ms, 72.77%
//dp问题
//直接使用空间优化版:用一个数组记录某一天所有可能操作下的最大利润
//(0:无, 1仅买一次, 2买卖一次, 3买卖一次然后仅买一次, 4买卖两次)的最大利润(这可能是负的, 在买入情况时)

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0) return 0;

		//含义见上面的注释
		int dp0 = 0;
		int dp2 = 0;
		int dp4 = 0; 
		int dp1 = -1 * prices[0];
		int dp3 = -1 * prices[0];
		//可能前几天有非法情况,这实际上不要紧:)
		for (int i = 1; i < prices.size(); i++)
		{
			//dp[i][0] = dp[i - 1][0];
			dp1 = max(dp1, dp0 - prices[i]);
			dp2 = max(dp2, dp1 + prices[i]);
			dp3 = max(dp3, dp2 - prices[i]);
			dp4 = max(dp4, dp3 + prices[i]);
		}

		return max(dp0, max(dp2, dp4));
	}
};
