#include "public.h"

//60ms, 46.81%
//dp[i][p]: 取前i个rods的时候, 高度差为p的时候, 最高的广告牌
//初始化所有的dp都是INT_MIN, dp[0][0] = 0;
//对rods遍历, (0<=i<rods.size())
//存在以下三种情况: 新的rod不加, 那么dp[i][p] = dp[i-1][p], 0<=p<=5000
//新的rod加到长端: dp[i][j+h] = max(dp[i][j+h] , dp[i][j] + h)
//新的rod加到短端: dp[i][abs(j-h)] = max( dp[i][abs(j-h)] , dp[i-1][j] + min(j, h) )

//最终求dp[rods.size()][0]

class Solution {
public:
	int tallestBillboard(vector<int>& rods) {
		int len = rods.size();
		vector<vector<int>> dp(len + 1, vector<int>(5001, -5001));
		int sum = 0;
		dp[0][0] = 0;
		for (int i = 1; i <= len; i++) {
			sum += rods[i - 1];
			for (int j = 0; j <= sum; j++) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j]);
				if (j + rods[i - 1] <= sum)
					dp[i][j + rods[i - 1]] = max(dp[i - 1][j], dp[i][j + rods[i - 1]]);

				dp[i][abs(j - rods[i - 1])] = max(dp[i][abs(j - rods[i - 1])], dp[i - 1][j] + min(j, rods[i - 1]));
			}
		}
		return dp[len][0];
	}
};
