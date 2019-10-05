#include "public.h"

//
//DP问题
//dp[i][j]: 下标从i到j最长回文


class Solution {
private:
	int longestPalindromeSubseq(string s) {
		int sSize = s.size();
		vector<vector<int>> dp(sSize, vector<int>(sSize, 1));

		int res = 1;
		//init
		for (int index = 0; index < s.size() - 1; ++index)
		{
			if (s[index] == s[index + 1])
			{
				dp[index][index + 1] = 2;
				res = 2;
			}
		}

		//递推
		for (int length = 3; length <= s.size(); ++length)
		{
			for (int start = 0; start <= s.size() - length; ++start)
			{
				int end = start + length - 1;
				if (s[start] == s[end])
				{
					dp[start][end] = 2 + dp[start + 1][end - 1];
					res = max(res, dp[start][end]);
				}
				else
				{
					dp[start][end] = max(dp[start + 1][end], dp[start][end - 1]);
				}
			}
		}
		return res;
	}
public:
	bool isValidPalindrome(string s, int k) {
		int biggest = longestPalindromeSubseq(s);
		int sSize = s.size();
		return (sSize - k) <= biggest;
	}
};
