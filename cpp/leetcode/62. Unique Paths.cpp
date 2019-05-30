#include "public.h"

//4ms, 96.63%

//DP problem, simpily that dp[i][j]=dp[i-1][j]+dp[i][j-1];
// Here, note that we do not need to store all dp, we can refresh one line by oneline dp[col] += dp[col - 1];

class Solution {
public:
	int uniquePaths(int m, int n) {
		//m¡–n––

		vector<int> dp(m, 1);

		for (int row = 0; row < n; ++row)
			for (int col = 1; col < m; col++)
				dp[col] += dp[col - 1];
		return dp[m-1];
	}
};