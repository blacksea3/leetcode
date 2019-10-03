#include "public.h"

//40ms, 97.13%
//DP problem
//每一个当前的金额都可以用coins中的任意一个加上之前的金额数量获得, 然后扣出最小值即可

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		sort(coins.begin(), coins.end());
		vector<int> dp(amount + 1, 0x7f7f7f7f);

		dp[0] = 0;

		for (int i = 1; i <= amount; ++i)
		{
			//挨个凑
			int mintemp = 0x7f7f7f7f;
			for (int c = 0; c < coins.size(); ++c)
			{
				int history = i - coins[c];
				if (history < 0) break;
				else mintemp = min(mintemp, dp[history] + 1);
			}
			dp[i] = mintemp;
		}
		return dp[amount] < 0x7f7f7f7f ? dp[amount] : -1;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> coins = { 1,2,5 };
	cout << s->coinChange(coins, 11);
	return 0;
}
*/
