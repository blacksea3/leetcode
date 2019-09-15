#include "public.h"

//
//递归

class Solution {
private:
	//假设外面有个括号
	//startloc已经在括号里了(左括号loc+1)
	//返回内部字符串和对应右括号loc+1
	pair<string, int> recu(string s, int startloc)
	{
		string res = "";
		int loc = startloc;
		while (loc < s.size())
		{
			if (s[loc] == '(')
			{
				pair<string, int> temp = recu(s, loc + 1);
				res += temp.first;
				loc = temp.second;
			}
			else if (s[loc] == ')')
			{
				reverse(res.begin(), res.end());
				return pair<string, int>{res, loc + 1};
			}
			else
			{
				res.push_back(s[loc]);
				loc++;
			}
		}
		//理论上不会到这里
		return pair<string, int>{"!!!", -1};
	}

public:
	string reverseParentheses(string s) {
		string res = "";
		int loc = 0;
		while (loc < s.size())
		{
			if (s[loc] != '(')
			{
				res.push_back(s[loc]);
				loc++;
			}
			else
			{
				pair<string, int> temp = recu(s, loc + 1);
				res += temp.first;
				loc = temp.second;
			}
		}
		return res;
	}
};
