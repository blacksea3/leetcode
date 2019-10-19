#include "public.h"

//
//dp?
//dp[i][j]: 抛了i枚硬币之后值是j的情况

class Solution {
public:
	double probabilityOfHeads(vector<double>& prob, int target) {
		int pSize = prob.size();

		vector<vector<double>> dp(pSize + 1, vector<double>(target + 1, 0));
		dp[0][0] = 1.0;

		for (int p = 1; p <= pSize; ++p)
		{
			dp[p][0] = dp[p - 1][0] * (1 - prob[p - 1]);
			for (int j = 1; j <= target; ++j)
			{
				dp[p][j] = dp[p - 1][j - 1] * prob[p - 1] + dp[p - 1][j] * (1 - prob[p - 1]);
			}
		}

		return dp[pSize][target];
	}
};


