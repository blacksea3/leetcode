#include "public.h"

//12ms, 98.14%

//�ȸ���139��ó��Ƿ���Բ��,Ȼ����DFS����

class Solution {
private:
	bool wordBreak_139(string s, vector<string>& wordDict)
	{
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
	void DFS(const string& s, const unordered_set<string>& wordd, int start, vector<string> pre,
		const int& minlen, const int& maxlen)
	{
		if (start == s.size()) res.push_back(generate_space_sentense(pre));
		for (int len = minlen; len <= maxlen; len++)
		{
			if ((start + len) > s.size()) break;
			if (wordd.find(s.substr(start, len)) != wordd.end())
			{
				pre.push_back(s.substr(start, len));
				DFS(s, wordd, start + len, pre, minlen, maxlen);
				pre.pop_back();
			}
		}
	}

public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		//�ȸ���139��,������������
		if (!wordBreak_139(s, wordDict)) return vector<string>{};

		unordered_set<string> wordd(wordDict.begin(), wordDict.end());

		int minlen = INT_MAX;
		int maxlen = 0;
		int maxloc_p1 = s.size();

		for (auto word : wordd)
		{
			minlen = min(minlen, (int)word.size());
			maxlen = max(maxlen, (int)word.size());
		}

		DFS(s, wordd, 0, {}, minlen, maxlen);
		return res;
	}
};