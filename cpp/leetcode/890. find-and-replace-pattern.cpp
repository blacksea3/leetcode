#include "public.h"

//4ms, 98.25%
//暴力, 用vector<char, char> 记录映射(双向的, 所以要两个vector)

class Solution {
public:
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> res;
		for (auto& w : words)
		{
			int loc = 0;
			bool isok = true;
			vector<char> v(256, 0);
			vector<char> r(256, 0);
			while (loc < pattern.size())
			{
				if (v[pattern[loc]] == 0 && r[w[loc]] == 0)
				{
					v[pattern[loc]] = w[loc];
					r[w[loc]] = pattern[loc];
				}
				else
				{
					if (v[pattern[loc]] != w[loc] || r[w[loc]] != pattern[loc])
					{
						isok = false;
						break;
					}
				}
				loc++;
			}
			if (isok) res.push_back(w);
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<string> words = { "abc","deq","mee","aqq","dkd","ccc" };
	auto res = s->findAndReplacePattern(words, "abb");
	return 0;
}
*/
