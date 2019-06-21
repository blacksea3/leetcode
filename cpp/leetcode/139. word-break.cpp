#include "public.h"

//���ƻ��ݵĶ�̬�滮, 12ms, 86.89%

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		//dp[i]:  0<=i<s.size()  ��ʾs�ĵ�һ������i�±굥�ʿ��Ա��γ�

		vector<bool> dp(s.size(), false);
		unordered_set<string> wordd(wordDict.begin(), wordDict.end());

		//��ȡ��ַ�������,��������ѭ������
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
