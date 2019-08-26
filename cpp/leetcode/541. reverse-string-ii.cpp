#include "public.h"

//20ms, 6.32%
//Ä£Äâ

class Solution {
public:
	string reverseStr(string s, int k) {
		int loc = 0;

		while (loc + 2 * k <= s.size())
		{
			reverse(s.begin() + loc, s.begin() + loc + k);
			loc += 2 * k;
		}

		if (loc + k >= s.size())
		{
			reverse(s.begin() + loc, s.begin() + s.size());
		}
		else
		{
			reverse(s.begin() + loc, s.begin() + loc + k);
		}
		return s;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->reverseStr("abcdefg", 2);
	return 0;
}
*/
