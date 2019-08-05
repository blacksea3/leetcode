#include "public.h"

//20ms, 44.09%
//dp[i][M]表示第i堆石子到最后, 先拿者的最大量, 0是最大
//从最后的石子往前递推

class Solution {
public:
	int stoneGameII(vector<int>& piles) {
		vector<vector<int>> dp(piles.size() + 1, vector<int>(piles.size() + 1, 0));

		//反过来递推
		for (int i = 1; i <= piles.size(); ++i)
		{
			dp[piles.size()][i] = 0;
		}

		int remainsum = 0;

		for (int loc = piles.size() - 1; loc >= 0; --loc)
		{
			for (int m = 1; m <= piles.size(); ++m)
			{
				int pmax = INT_MIN;
				int pmin = INT_MAX;
				int psum = 0;
				int tempremainsum = remainsum;
				for (int i = 1; i + loc <= piles.size() && i <= 2 * m; ++i)
				{
					psum += piles[loc + i - 1];
					pmax = max(pmax, psum + (tempremainsum - dp[loc + i][max(i, m)]));
					if (i + loc == piles.size())
					{
						pmax = max(pmax, psum);
					}
					else
					{
						tempremainsum -= piles[loc + i];
					}
				}
				dp[loc][m] = pmax;
			}
			remainsum += piles[loc];
		}
		return dp[0][1];
	}
};
