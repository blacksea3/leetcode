#include "public.h"

//可以用hashmap, 16ms, 71.80%

/*
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		//维护两个转换表就可以
		unordered_map<char, char> um;
		unordered_map<char, char> um_r;

		if (s.size() != t.size()) return false;
		for (int i = 0; i < s.size(); i++)
		{
			if (um.find(s[i]) == um.end())
			{
				if (um_r.find(t[i]) == um_r.end())
				{
					um[s[i]] = t[i];
					um_r[t[i]] = s[i];
				}
				else
				{
					return false;
				}
			}
			else if (um_r.find(t[i]) == um_r.end())
				return false;
			else
			{
				//注意自映射问题
				if ((s[i] == t[i]) && (um[s[i]] != s[i])) return false;
				else if ((s[i] != t[i]) && (um[s[i]] == s[i])) return false;
				else continue;
			}
		}
		return true;
	}
};*/

//16ms, 71.80%
//或者使用以下思路: 判断相同字符在相同位置就好了。
//这个意思是:对于s或t, 相同字符的首次出现位置一定是一致的!

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size()) return false;

		for (int i = 0; i < s.size(); ++i)
		{
			if (s.find(s[i]) != t.find(t[i]))
				return false;
		}
		return true;
	}
};
