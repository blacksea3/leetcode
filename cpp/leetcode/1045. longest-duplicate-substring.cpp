#include "public.h"

//内存超出, 待修改
//后缀数组
//把所有i下标至S末尾的子串保存, 并且排序, 求相邻字符串的公共前缀的最长长度

class Solution {
private:
	int common_prefix_length(string s1, string s2)
	{
		int res = 0;
		int loc = 0;
		while (loc < s1.size() && loc < s2.size() && s1[loc] == s2[loc]) loc++;
		return loc;
	}

public:
	string longestDupSubstring(string S) {
		vector<string> suffix(S.size());
		for (int i = 0; i < S.size(); ++i) suffix[i] = S.substr(i);
		string res = "";
		int maxlen = 0;
		sort(suffix.begin(), suffix.end());

		for (int i = 0; i < S.size() - 1; ++i)
		{
			int temp = common_prefix_length(suffix[i], suffix[i + 1]);
			if (temp > maxlen)
			{
				maxlen = temp;
				res = suffix[i].substr(0, maxlen);
			}
		}
		return res;
	}
};
