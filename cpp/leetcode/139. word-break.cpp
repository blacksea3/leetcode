#include "public.h"

//类似回溯的动态规划, 12ms, 86.89%

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		//dp[i]:  0<=i<s.size()  表示s的第一个至第i下标单词可以被形成

		vector<bool> dp(s.size(), false);
		unordered_set<string> wordd(wordDict.begin(), wordDict.end());

		//获取最长字符串长度,以缩减内循环长度
		int maxlen = 0;
		for (auto w : wordDict) maxlen = max(maxlen, (int)w.size());

		for (int i = 0; i < s.size(); i++)
			for (int j = max(0, i - maxlen + 1); j <= i; j++)
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
