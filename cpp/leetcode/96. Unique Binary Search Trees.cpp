#include "public.h"

//4ms, 72.24%
//DP, dp[i]��ʾn=i�Ķ�������������
//����dp[18] = ���dp[i]*dp[17-i] i=0��17
//��ʼ��dp[0] = 1

class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1);
		if (n <= 0) return 0;
		dp[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0, j_add1 = 1; j < i; j++, j_add1++)
			{
				dp[i] += dp[j] * dp[i - j_add1];
			}
		}
		return dp[n];
	}
};
