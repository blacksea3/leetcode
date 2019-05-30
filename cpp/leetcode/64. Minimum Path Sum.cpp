#include "public.h"

//12ms, 95.27%

//similar to problem 63

//we can refresh one line by one line
//dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		//special input
		int n = grid.size();
		if (n == 0) return 0;
		int m = grid[0].size();
		if (m == 0) return 0;

		vector<long> dp(m, 0);

		dp[0] = grid[0][0];

		for (int j = 1; j < m; j++) dp[j] = dp[j - 1] + grid[0][j];

		for (int i = 1; i < n; i++)
		{
			dp[0] += grid[i][0];
			for (int j = 1; j < m; j++)
			{
				dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
			}
		}

		return dp[m - 1];
	}

};