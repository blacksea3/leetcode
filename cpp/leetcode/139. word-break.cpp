#include "public.h"

//4ms, 97.69%
//��̬�滮
//dp[i]:  0<=i<s.size()  ��ʾs�ĵ�һ������i�±굥�ʿ��Ա��γ�

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.size(), false);
		unordered_set<string> wordd(wordDict.begin(), wordDict.end());

		//��ȡ��ַ�������,��������ѭ������
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
