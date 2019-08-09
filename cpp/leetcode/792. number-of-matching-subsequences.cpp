#include "public.h"

//252ms, 67.26%
//半暴力
//给words拉一个vector<vector<int>> pre_locs: 表示首字母: words索引
//然后一遍扫描S一遍操作pre_locs, 对于找到首字母的, 把接下来的字符串分别放置在pre_locs合适位置, 按第二字母放

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
