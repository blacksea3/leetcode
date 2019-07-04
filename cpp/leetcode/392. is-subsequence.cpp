#include "public.h"

//60ms, 80.26%
//к╚об╠Й

class Solution {
public:
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
};
