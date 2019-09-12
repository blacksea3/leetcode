#include "public.h"

//0ms, 100%
//就是斐波那契数列, 用dp操作

class Solution {
public:
	int climbStairs(int n) {
		if (n <= 2) return n; //特殊情况
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; ++i)
			dp[i] = dp[i - 1] + dp[i - 2];
		return dp[n];
	}
};