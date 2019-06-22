#include "public.h"

//simple solution 12ms, 90.58%
//状态机,分读取字母和读取空格

class Solution {
public:
	string reverseWords(string s) {
		int loc = s.size() - 1;
		int wordend = 0;

		bool iswording = false;   //true:当前正在读取文字

		string res = "";

		while (loc >= 0)
		{
			if (iswording)
			{
				if (s[loc] == ' ')
				{
					res += s.substr(loc + 1, wordend - loc);
					res += " ";
					iswording = false;
				}
			}
			else
			{
				if (s[loc] != ' ')
				{
					iswording = true;
					wordend = loc;
				}
			}
			loc--;
		}
		if (iswording)  //添加最后一个单词
			res += s.substr(0, wordend + 1);
		else  //去除末尾空格
			res.pop_back();
		return res;
	}
};