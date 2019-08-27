#include "public.h"

//88ms, 86.27%
//暴力, 挨个判断

class Solution {
private:
	//返回:s是否为t的子序列
	bool isSubsequence(string s, string t) {
		int sloc = 0;
		int tloc = 0;

		while (sloc < s.size() && tloc < t.size())
		{
			if (t[tloc] == s[sloc])
			{
				tloc++;
				sloc++;
			}
			else tloc++;
		}
		if (sloc == s.size()) return true;
		else return false;
	}

public:
	string findLongestWord(string s, vector<string>& d) {
		string res = "";
		int matchLen = 0;

		for (auto& iter_d : d)
		{
			if (isSubsequence(iter_d, s))
			{
				if (matchLen < iter_d.size())
				{
					res = iter_d;
					matchLen = iter_d.size();
				}
				else if (matchLen == iter_d.size())
				{
					res = min(res, iter_d);
				}
			}
		}
		return res;
	}
};
