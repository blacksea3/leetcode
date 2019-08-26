#include "public.h"

//32ms, 46.41%
//模拟, 读取空格位置

class Solution {
public:
	string reverseWords(string s) {
		int lastspace = -1;

		int loc = 0;
		while (loc < s.size())
		{
			while (loc < s.size() && s[loc] != ' ') loc++;
			reverse(s.begin() + lastspace + 1, s.begin() + loc);
			lastspace = loc;
			loc++;
		}
		return s;
	}
};
