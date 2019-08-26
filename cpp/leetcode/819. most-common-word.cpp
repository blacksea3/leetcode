#include "public.h"

//16ms, 30.93%
//统计词频, 然后分别与banned比较

class Solution {
private:
	string convert2lower(string pre)
	{
		for (auto& p : pre)
		{
			if (p <= 'Z' && p >= 'A') p = p - 'A' + 'a';
		}
		return pre;
	}


public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		unordered_map<string, int> um;
		unordered_set<string> usban(banned.begin(), banned.end());

		int loc = 0;
		string pre = "";
		while (loc < paragraph.size())
		{
			if (isalpha(paragraph[loc]))
			{
				pre.push_back(paragraph[loc]);
			}
			else
			{
				if (!pre.empty())
				{
					um[convert2lower(pre)]++;
					pre = "";
				}
			}
			loc++;
		}
		if (!pre.empty())
		{
			um[convert2lower(pre)]++;
		}

		//判断
		int maxfre = INT_MIN;
		string res;

		for (auto& ium : um)
		{
			if (usban.find(ium.first) == usban.end() && ium.second > maxfre)
			{
				maxfre = ium.second;
				res = ium.first;
			}
		}
		return res;
	}
};
