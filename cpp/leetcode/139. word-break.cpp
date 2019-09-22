#include "public.h"

//4ms, 97.69%
//动态规划
//dp[i]:  0<=i<s.size()  表示s的第一个至第i下标单词可以被形成

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.size(), false);
		unordered_set<string> wordd(wordDict.begin(), wordDict.end());

		//获取最长字符串长度,以缩减内循环长度
		size_t maxlen = 0;
		for (auto& w : wordDict) maxlen = max(maxlen, w.size());

		for (size_t i = 0; i < s.size(); i++)
			for (size_t j = ((i + 1) > maxlen) ? (i + 1 - maxlen) : 0; j <= i; j++)
			{
				if (((j == 0) || dp[j - 1]) && (wordd.find(s.substr(j, i - j + 1)) != wordd.end()))
				{
					dp[i] = true;
					break;
				}
			}
		return dp[s.size() - 1];
	}
};
