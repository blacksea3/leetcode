#include "public.h"

//4ms, 99.14%
//动态规划
//dp[i][j]表示S的前i个字符包含了T的前j个字符 的 子序列的个数
//举例对 123546 与  125 因为 12354与125是1, 6!=5 所以 123546 与  125是1
//对 123545 与  125 因为 12354与125是1, 6!=5 所以 123545 与  125是12354与125(多出来的5不使用),加上12354与12(多出来的5使用)
//应该先给j遍历,以提高t的长度
//然后给i遍历,以提高s的长度
//所有t空s有的情况均认为是1
//所有t有s空的情况均认为是0,以及一些t比s长的情况跳过

class Solution {
public:
	int numDistinct(string s, string t) {
		size_t ts = t.size();
		size_t ss = s.size();

		vector<vector<unsigned int>> dp(ts + 1, vector<unsigned int>(ss + 1, 0));

		for (size_t i = 0; i <= ss; i++) dp[0][i] = 1;
			
		for (size_t j = 1; j <= ts; j++)
			for (size_t i = 1; i <= ss; i++)
				if (s[i - 1] == t[j - 1])
					//如果用int, 会overflow?!?!?!?
					//根据题目意思,这里overflow,绝对不可能成为结果!
					dp[j][i] = dp[j][i - 1] + dp[j - 1][i - 1];
				else
					dp[j][i] = dp[j][i - 1];

		return dp[t.size()][s.size()];
	}
};
