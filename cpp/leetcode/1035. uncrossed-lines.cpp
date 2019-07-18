#include "public.h"

//16ms, 92.07%

//dp
//dp[i][j]: A[0]至A[i-1], B[0]至[j-1]的最大连线数
//dp[0][?] = 0, dp[?][0] = 0

class Solution {
public:
	int maxUncrossedLines(vector<int>& A, vector<int>& B) {
		//vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
		int** dp = new int* [A.size()+1];
		for (int i = 0; i <= A.size(); ++i)
		{
			dp[i] = new int[B.size() + 1];
		}

		for (int i = 0; i <= A.size(); ++i)
		{
			dp[i][0] = 0;
		}
		for (int j = 1; j <= B.size(); ++j)
		{
			dp[0][j] = 0;
		}

		for (int i = 1; i <= A.size(); ++i)
			for (int j = 1; j <= B.size(); ++j)
			{
				if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		return dp[A.size()][B.size()];
	}
};
