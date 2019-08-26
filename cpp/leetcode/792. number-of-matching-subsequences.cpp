#include "public.h"

//252ms, 67.26%
//�뱩��
//��words��һ��vector<vector<int>> pre_locs: ��ʾ����ĸ: words����
//Ȼ��һ��ɨ��Sһ�����pre_locs, �����ҵ�����ĸ��, �ѽ��������ַ����ֱ������pre_locs����λ��, ���ڶ���ĸ��

class Solution {
public:
	int numMatchingSubseq(string S, vector<string>& words) {
		vector<vector<int>> pre_locs(26);

		for (int i = 0; i < words.size(); ++i)
		{
			pre_locs[words[i][0] - 'a'].push_back(i);
		}

		int res = 0;

		for (auto& iis : S)
		{
			vector<int> pre = pre_locs[iis - 'a'];
			if (!pre.empty())
			{
				pre_locs[iis - 'a'].clear();
				for (auto& word_loc : pre)
				{
					if (words[word_loc].size() == 1) res++;
					else
					{
						words[word_loc].erase(words[word_loc].begin());
						pre_locs[words[word_loc][0] - 'a'].push_back(word_loc);
					}
				}
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->numMatchingSubseq();
	return 0;
}
*/
