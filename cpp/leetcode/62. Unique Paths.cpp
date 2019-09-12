#include "public.h"

//0ms, 100%
//DP问题, dp[i][j]=dp[i-1][j]+dp[i][j-1];
//初始化 dp[0][0] = 1
//使用空间复杂度优化: 更新单行dp[col] += dp[col - 1];

class Solution {
public:
	int uniquePaths(int m, int n) {
		//m列
		vector<int> dp(m);
		dp[0] = 1;

		for (int row = 0; row < n; ++row)
			for (int col = 1; col < m; col++)
				dp[col] += dp[col - 1];
		return dp[m-1];
	}
};