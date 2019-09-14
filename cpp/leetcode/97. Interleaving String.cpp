#include "public.h"

//4ms, 94.58%
//DP问题
//定义dp[i][j]: s1.substr(0,i) + s2.substr(0,j) 能否交错成为 s3.substr(0,i+j)
//初始化when i == 0 and j == 0 , dp[i][j] = true
//for i == 0 and j ≠ 0 or j == 0 and i ≠ 0, dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]), the same is for j
//for j > 0 and j > 0, dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i-1+j]))|| (dp[i][j-i] && (s2[j-1] == s3[i-1+j]))
//then return dp[lens1][lens2]

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();

		if ((len1 + len2) != len3) return false;

		if (len1 == 0) return (s2 == s3);
		if (len2 == 0) return (s1 == s3);

		vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
		dp[0][0] = true;

		for (int i = 1; i <= len1; i++)
			dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
		for (int j = 1; j <= len2; j++)
			dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);

		for (int i = 1; i <= len1; i++)
			for (int j = 1; j <= len2; j++)
				dp[i][j] = ((dp[i - 1][j] && (s1[i - 1] == s3[i - 1 + j])) || (dp[i][j - 1] && (s2[j - 1] == s3[j - 1 + i])));

		return dp[len1][len2];
	}
};
