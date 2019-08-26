#include "public.h"

//4ms, 98.78%
/*
1. 考虑以下的状态：**dp[i]：走到第i阶梯的最小花费**
2. 递推公式则为：**dp[i] = min(dp[i-2], dp[i-1]) + cost[i]**
3. 初始值可以取：**dp[0] = cost[0], dp[1] = cost[1]**
4. 结果就是：**min(dp[cost.size()-1], dp[cost.size()-2])**
*/

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int l = cost.size();
		vector<int> dp(l);
		dp[0] = cost[0];
		dp[1] = cost[1];

		for (int i = 2; i < l; ++i) dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];

		return min(dp[l - 1], dp[l - 2]);
	}
};
