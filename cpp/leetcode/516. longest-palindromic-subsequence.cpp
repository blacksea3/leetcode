#include "public.h"

//216ms, 11.49%
//动态规划, 按长度扩展
//定义dp[i][j] 表示下标i至j, 左闭右闭
//初始化 dp[i][i] = 1; dp[i][i+1] = 1或2
//按长度, 对当前长度, 若左=右则结果等于2加内部, 若左!=右则结果等于max(去掉左边, 去掉右边)
//O(n^2)

class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int sSize = s.size();
		vector<vector<int>> dp(sSize, vector<int>(sSize, 1));

		//init
		for (int index = 0; index < s.size() - 1; ++index)
		{
			if (s[index] == s[index + 1])
			{
				dp[index][index + 1] = 2;
			}
		}

		int res = 1;
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
};
