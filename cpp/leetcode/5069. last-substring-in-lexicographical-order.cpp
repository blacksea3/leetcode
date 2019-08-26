#include "public.h"

//
//半暴力, 从头开始搜

/*
class Solution {
public:
	string lastSubstring(string s) {
		vector<pair<int, int>> initloc;
		char biggest = 'a' - 1;

		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] > biggest)
			{
				biggest = s[i];
				initloc.clear();
				initloc.push_back(pair<int, int>{i, i});
			}
			else if (s[i] == biggest)
			{
				initloc.push_back(pair<int, int>{i, i});
			}
		}


		while (initloc.size() > 1)
		{
			char biggest = 'a' - 1;
			vector<int> updateloc;
			for (int i = 0; i < initloc.size(); ++i)
			{
				int secondloc = initloc[i].second + 1;
				if (secondloc < s.size())
				{
					if (s[secondloc] > biggest)
					{
						biggest = s[secondloc];
						updateloc.clear();
						updateloc.push_back(i);
					}
					else if (s[secondloc] == biggest)
					{
						updateloc.push_back(i);
					}
				}
			}
			vector<pair<int, int>> nextloc;
			for (int k = 0; k < updateloc.size(); ++k)
			{
				pair<int, int> temp = initloc[updateloc[k]];
				temp.second++;
				nextloc.push_back(temp);
			}
			initloc = nextloc;
		}
		return s.substr(initloc[0].first);
	}
};
*/

//
//半暴力, 从头开始搜
//c++ TLE, 但是亲测python不会, 我的c++使用不熟练

class Solution {
public:
	string lastSubstring(string s) {
		const char* c_strs = s.c_str();
		int resloc = 0;
		for (int i = 1; i < s.size(); ++i)
		{
			if (strcmp(c_strs + i, c_strs + resloc) >= 0)
			{
				resloc = i;
			}
		}
		return s.substr(resloc);
	}
};

int main()
{
	Solution*s = new Solution();
	auto res0 = s->lastSubstring("zrziy");
	auto res = s->lastSubstring("abab");
	auto res1 = s->lastSubstring("leetcode");
	auto res2 = s->lastSubstring("xbylisvborylklftlkcioajuxwdhahdgezvyjbgaznzayfwsaumeccpfwamfzmkinezzwobllyxktqeibfoupcpptncggrdqbkji");
	return 0;
}
