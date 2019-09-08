#include "public.h"

//52ms, 14.34%
//dp[i][j]:表示word1的前i和字母和word2的前j个字母相同所需最小步数
//初始化:dp[0][x]=x, dp[y][0] = y
//更新: 如果word1[i-1]==word2[j-1], 则dp[i][j] = dp[i-1][j-1], 否则dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int word1Size = word1.size();
		int word2Size = word2.size();

		vector<vector<int>> dp(word1Size + 1, vector<int>(word2Size + 1, 0));

		for (int i = 1; i <= word1Size; ++i)
		{
			dp[i][0] = i;
		}
		for (int j = 1; j <= word2Size; ++j)
		{
			dp[0][j] = j;
		}

		for (int i = 1; i <= word1Size; ++i)
		{
			for (int j = 1; j <= word2Size; ++j)
			{
				if (word1[i - 1] == word2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
				}
			}
		}
		return dp[word1Size][word2Size];
	}
};
