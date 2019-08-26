#include "public.h"

//48ms, 54.17%
//dp problem
//dp[i][j]表示str1[0:i] 与 str2[0:j]的相同子序列长度, 注意并没有到i与j, 左闭右开

class Solution {
public:
	string shortestCommonSupersequence(string str1, string str2) {
		int s1 = str1.size();
		int s2 = str2.size();

		vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));
		for (int row = 0; row <= s1; row++)
			dp[row][0] = 0;
		for (int column = 0; column <= s2; column++)
			dp[0][column] = 0;

		for (int i = 1; i <= s1; i++)
			for (int j = 1; j <= s2; j++)
			{
				if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else if (dp[i][j - 1] > dp[i - 1][j])
					dp[i][j] = dp[i][j - 1];
				else
					dp[i][j] = dp[i - 1][j];
			}

		//倒着访问回去                       
		int pres1 = s1;
		int pres2 = s2;

		string res = "";

		while ((pres1 >= 0) && (pres2 >= 0))
		{
			int whichdir = 0;
			if ((pres1 > 0) && (pres2 > 0))
			{
				if ((dp[pres1 - 1][pres2 - 1] == dp[pres1][pres2 - 1]) &&
					(dp[pres1 - 1][pres2 - 1] == dp[pres1 - 1][pres2]))
				{
					if (dp[pres1 - 1][pres2 - 1] < dp[pres1][pres2])
					{
						res.insert(res.begin(), str1[pres1 - 1]);
						pres1--;
						pres2--;
					}
					else
					{
						res.insert(res.begin(), str2[pres2 - 1]);
						pres2--;
					}
				}
				else if (dp[pres1 - 1][pres2 - 1] < dp[pres1][pres2 - 1])
				{
					if (str1[pres1 - 1] == str2[pres2 - 1])
					{
						res.insert(res.begin(), str1[pres1 - 1]);
						pres1--;
						pres2--;
					}
					else
					{
						res.insert(res.begin(), str2[pres2 - 1]);
						pres2--;
					}
				}
				else
				{
					if (str1[pres1 - 1] == str2[pres2 - 1])
					{
						res.insert(res.begin(), str1[pres1 - 1]);
						pres1--;
						pres2--;
					}
					else
					{
						res.insert(res.begin(), str1[pres1 - 1]);
						pres1--;
					}
				}
			}
			else if (pres1 > 0)
			{
				res.insert(res.begin(), str1[pres1 - 1]);
				pres1--;
			}
			else if (pres2 > 0)
			{
				res.insert(res.begin(), str2[pres2 - 1]);
				pres2--;
			}
			else break;
		}
		return res;
	}
};
