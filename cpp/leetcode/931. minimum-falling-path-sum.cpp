#include "public.h"

//12ms, 97.94%
//dp从上到下
//按行dp
//

class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& A) {
		//单列单独处理
		int columns = A[0].size();

		if (columns == 1)
		{
			int res = 0;
			for (int r = 0; r < A.size(); ++r)
				res += A[r][0];
			return res;
		}
		else
		{
			vector<int> dp(columns, 0);
			for (int c = 0; c < columns; ++c)
			{
				dp[c] = A[0][c];
			}

			for (int r = 1; r < A.size(); ++r)
			{
				vector<int> tempdp(columns);
				tempdp[0] = min(dp[0], dp[1]) + A[r][0];
				tempdp[columns - 1] = min(dp[columns - 1], dp[columns - 2]) + A[r][columns - 1];
				for (int c = 1; c < columns - 1; ++c)
				{
					tempdp[c] = min(dp[c - 1], min(dp[c], dp[c + 1])) + A[r][c];
				}
				dp = tempdp;
			}

			int res = INT_MAX;
			for (int c = 0; c < columns; ++c)
				res = min(res, dp[c]);
			return res;
		}
	}
};
