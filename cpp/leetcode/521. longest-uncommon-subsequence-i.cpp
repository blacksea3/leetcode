#include "public.h"

//0ms, 100%
//如果俩字符串一样那就是-1, 否则是长的字符串的长度

class Solution {
public:
	int findLUSlength(string a, string b) {
		if (a == b) return -1;
		else return max(a.size(), b.size());
	}
};
