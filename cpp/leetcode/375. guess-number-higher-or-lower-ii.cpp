#include "public.h"

//36ms, 44.48%
//������dp
//dp[i][j]��ʾ��i+1��j+1����������
//����: init  dp[i][i] = 0
//  dp[i][j] = max(i+1+dp[i+1][j]  +  i+2+dp[i][i]+dp[i+2][j]  +  ...  +   j+1+dp[i][j-1])

class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n, vector<int>(n, 0)); //������ʼ��Ч��

		for (int lenm1 = 1; lenm1 <= n - 1; ++lenm1)
		{
			for (int left = 0; left <= n - 1 - lenm1; ++left)
			{
				int tempmin = INT_MAX;
				tempmin = min(tempmin, left + 1 + dp[left + 1][left + lenm1]);
				tempmin = min(tempmin, left + lenm1 + 1 + dp[left][left + lenm1 - 1]);
				for (int k = left + 1; k <= left + lenm1 - 1; ++k)
				{
					tempmin = min(tempmin, k + 1 + max(dp[left][k - 1], dp[k + 1][left + lenm1]));
				}
				dp[left][left + lenm1] = tempmin;
			}
		}
		return dp[0][n - 1];
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->getMoneyAmount(10);
	return 0;
}
*/
