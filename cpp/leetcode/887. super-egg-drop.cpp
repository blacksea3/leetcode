#include "public.h"

//40ms, 25.00%
//�ο�https://leetcode-cn.com/problems/two-sum/solution/ji-dan-diao-luo-xiang-jie-by-shellbye/
//�Լ������ӵ��������3
//�����ö�����

class Solution {
public:
	int superEggDrop(int K, int N) {
		vector<vector<int>> dp(K + 1, vector<int>(N + 1));
		for (int m = 1; m <= N; ++m)
		{
			dp[0][m] = 0;
			for (int k = 1; k <= K; k++)
			{
				dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1;
				if (dp[k][m] >= N) {
					return m;
				}
			}
		}
		return N;
	}
};

