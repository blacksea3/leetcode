#include "public.h"

//12ms, 96.78%
//先复用139题得出是否可以拆分,然后再DFS回溯
class Solution {
private:
	bool wordBreak_139(string s, vector<string>& wordDict)
	{
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

	string generate_space_sentense(const vector<string>& input)
	{
		string s = input[0];
		for (int i = 1; i < input.size(); i++)
		{
			s += " ";
			s += input[i];
		}
		return s;
	}

	vector<string> res = {};
	void DFS(const string& s, const unordered_set<string>& wordd, int start, vector<string>& pre,
		size_t minlen, size_t maxlen)
	{
		if (start == s.size()) res.emplace_back(generate_space_sentense(pre));
		for (size_t len = minlen; len <= maxlen; len++)
		{
			if ((start + len) > s.size()) break;
			if (wordd.find(s.substr(start, len)) != wordd.end())
			{
				pre.emplace_back(s.substr(start, len));
				DFS(s, wordd, start + len, pre, minlen, maxlen);
				pre.pop_back();
			}
		}
	}

public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		//先复用139题,如果可以则回溯
		if (!wordBreak_139(s, wordDict)) return vector<string>{};

		unordered_set<string> wordd(wordDict.begin(), wordDict.end());

		size_t minlen = INT_MAX;
		size_t maxlen = 0;
		int maxloc_p1 = s.size();

		for (auto& word : wordd)
		{
			minlen = min(minlen, word.size());
			maxlen = max(maxlen, word.size());
		}

		vector<string> pre;
		DFS(s, wordd, 0, pre, minlen, maxlen);
		return res;
	}
};
