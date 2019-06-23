#include "public.h"

//20ms 97.21%

//新建一个vector保存各行的字符串
//然后按规则读取s即可
//注意行的移动方向:上或者下
//注意特殊情况:只有一行

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;

		vector<string> group_s(numRows);
		bool downdir = true;
		int line = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			group_s[line] += s[i];
			if (line == 0) downdir = true;
			if (line == (numRows - 1)) downdir = false;

			if (downdir) ++line;
			else --line;
		}

		string returns;
		for (auto& str:group_s)
			returns += str;
		return returns;
	}
};

