#include "public.h"

//72ms, 91.36%
//�����ȱ���(�������), ͨ��isfront_body�ж�������

class Solution {
private:
	bool isfront_body(string word1, string word2)
	{
		int i = 0;
		int j = 0;
		while ((i < word1.size()) && (word1[i] == word2[j]))
		{
			i++;
			j++;
		}
		if (i == word1.size()) return true;
		j++;
		while ((j < word2.size()) && (word1[i] == word2[j]))
		{
			i++;
			j++;
		}
		if (j == word2.size()) return true;
		else return false;
	}

public:
	int longestStrChain(vector<string>& words) {
		//ע�⵽���ʳ����Ϊ16
		vector<vector<pair<string, int>>> v(16, vector<pair<string, int>>{}); //��¼�ַ���, ���Լ�Ϊֹ��������

		for (auto word : words)
			v[word.size() - 1].push_back(pair<string, int>{word, 1});

		int may_maxlen = 1;
		int maxlen = 1;

		int temp = 0;
		for (auto iter_v : v)
		{
			if (iter_v.empty())
			{
				may_maxlen = max(may_maxlen, temp);
				temp = 0;
			}
			else temp++;
		}
		may_maxlen = max(may_maxlen, temp);

		//�����ȱ�������
		for (int i = 1; i < 16; i++)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				pair<string, int> pair_bigword = v[i][j];
				for (int k = 0; k < v[i - 1].size(); k++)
				{
					pair<string, int> pair_smallword = v[i - 1][k];
					if (isfront_body(pair_smallword.first, pair_bigword.first))
					{
						v[i][j].second = max(v[i][j].second, pair_smallword.second + 1);
						maxlen = max(maxlen, v[i][j].second);
						if (maxlen == may_maxlen) return may_maxlen;
					}
				}
			}
		}
		return maxlen;
	}
};

