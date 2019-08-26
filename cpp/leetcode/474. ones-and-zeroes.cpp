#include "public.h"

//248ms, 21.24%
//背包问题
//dp[j][k]: 使用j个0, k个1的最大数量
//哨兵值: dp[0][0] = 0
//0<=j<=m, 0<=k<=n
//对字符串遍历
//  dp[j][k] = max(dp[j][k], dp[j-个数][k-个数]+1)

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

		dp[0][0] = 0;

		for (auto& str : strs)
		{
			int countOne = 0;
			int countZero = 0;
			for (auto& iter_str : str)
			{
				if (iter_str == '1') countOne++;
				else countZero++;
			}

			for (int iterCountOne = n; iterCountOne >= countOne; iterCountOne--)
			{
				for (int iterCountZero = m; iterCountZero >= countZero; iterCountZero--)
				{
					dp[iterCountZero][iterCountOne] = max(dp[iterCountZero][iterCountOne],
						dp[iterCountZero - countZero][iterCountOne - countOne] + 1);
				}
			}
		}
		return dp[m][n];   //注意:也许dp[m][n]会浪费多余的m/n但是它的值一定代表了最多的字符串数量(一定等于使用最多的字符串数量使用的0和1的个数的dp值)
	}
};
