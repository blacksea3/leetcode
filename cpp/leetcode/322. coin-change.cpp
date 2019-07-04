#include "public.h"

//68ms, 79.30%
//DP problem
//每一个当前的金额都可以用coins中的任意一个加上之前的金额数量获得, 然后扣出最小值即可

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {

		vector<int> dp(amount + 1, 0);

		for (int i = 1; i <= amount; ++i)
		{
			//挨个凑
			int mintemp = INT_MAX;
			bool haschance = false;
			for (int c = 0; c < coins.size(); ++c)
			{
				int history = i - coins[c];
				if ((history >= 0) && (dp[history] != -1))
				{
					mintemp = min(mintemp, dp[history] + 1);
					haschance = true;
				}
			}
			if (haschance) dp[i] = mintemp;
			else dp[i] = -1;
		}
		return dp[amount];
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> coins = { 2 };
	cout << s->coinChange(coins, 3);
	return 0;
}
*/
