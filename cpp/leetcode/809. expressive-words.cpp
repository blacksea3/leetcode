#include "public.h"

//8ms, 90.67%
//暴力, 依次扫描

class Solution {
public:
	int expressiveWords(string S, vector<string>& words) {
		//扫描S, 获取其每个字符相应的重复次数
		vector<pair<char, int>> vs;
		int oldchar = S[0];
		int oldlen = 1;
		int loc = 1;
		while (loc < S.size())
		{
			if (S[loc] == oldchar) oldlen++;
			else
			{
				vs.push_back({ oldchar, oldlen });
				oldchar = S[loc];
				oldlen = 1;
			}
			loc++;
		}
		vs.push_back({ oldchar, oldlen });

		//扫描words
		int res = 0;
		for (auto& word : words)
		{
			bool isok = true;
			int woldchar = word[0];
			int woldlen = 1;
			int wloc = 1;
			int absloc = 0;
			while (wloc < word.size())
			{
				if (word[wloc] == woldchar) woldlen++;
				else
				{
					if (absloc < vs.size() && woldchar == vs[absloc].first && (woldlen == vs[absloc].second || (vs[absloc].second >= 3 && woldlen < vs[absloc].second)))
					{
						woldchar = word[wloc];
						woldlen = 1;
						absloc++;
					}
					else
					{
						isok = false;
						break;
					}
				}
				wloc++;
			}
			//最后一段
			if (isok)
			{
				if (absloc == (vs.size() - 1) && woldchar == vs[absloc].first && (woldlen == vs[absloc].second || (vs[absloc].second >= 3 && woldlen < vs[absloc].second)))
				{
					res++;
				}
			}
		}
		return res;
	}
};
