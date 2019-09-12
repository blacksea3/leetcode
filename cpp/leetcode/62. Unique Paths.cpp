#include "public.h"

//0ms, 100%
//DP����, dp[i][j]=dp[i-1][j]+dp[i][j-1];
//��ʼ�� dp[0][0] = 1
//ʹ�ÿռ临�Ӷ��Ż�: ���µ���dp[col] += dp[col - 1];

class Solution {
public:
	int uniquePaths(int m, int n) {
		//m��
		vector<int> dp(m);
		dp[0] = 1;

		for (int row = 0; row < n; ++row)
			for (int col = 1; col < m; col++)
				dp[col] += dp[col - 1];
		return dp[m-1];
	}
};