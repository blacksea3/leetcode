#include "public.h"

//168ms, 30.59%
//dp[i]:最后落到i号键的电话号码种数

class Solution {
public:
	int knightDialer(int N) {
		vector<long long> dp(10, 1);
		long long MOD = 1000000007;
		for (int i = 1; i < N; ++i)
		{
			vector<long long> next(10, 0);
			next[0] = dp[4] + dp[6];
			next[1] = dp[8] + dp[6];
			next[2] = dp[7] + dp[9];
			next[3] = dp[4] + dp[8];
			next[4] = dp[3] + dp[9] + dp[0];
			next[5] = 0;
			next[6] = dp[1] + dp[7] + dp[0];
			next[7] = dp[2] + dp[6];
			next[8] = dp[1] + dp[3];
			next[9] = dp[2] + dp[4];

			dp = next;
			for (int j = 0; j < 10; ++j)
			{
				dp[j] %= MOD;
			}	
		}
		long long res = accumulate(dp.begin(), dp.end(), (long long)0);
		return res % MOD;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->knightDialer(161);
	return 0;
}
*/
