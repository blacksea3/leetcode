#include "public.h"

//4ms, 90.85%
//����62��, �ռ临�Ӷ��Ż�, ����dp[j] += dp[j - 1] if obstacleGrid[prerow][j] == 1 else 0
//��Ҫ��ʼ����һ��

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		//�����������
		int n = obstacleGrid.size();
		if (n == 0) return 0;
		int m = obstacleGrid[0].size();
		if (m == 0) return 0;
		if (obstacleGrid[0][0] == 1) return 0;

		//m��n��

		vector<long> dp(m, 0);

		for (int j = 0; j < m; j++)
		{
			if (obstacleGrid[0][j] == 0) dp[j] = 1;
			else break;
		}

		for (int i = 1; i < n; i++)
		{
			if (obstacleGrid[i][0] == 1) dp[0] = 0;
			for (int j = 1; j < m; j++)
			{
				if (obstacleGrid[i][j] == 1) dp[j] = 0;
				else dp[j] += dp[j - 1];
			}
		}

		return (int)dp[m-1];
	}
};
