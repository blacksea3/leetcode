#include "public.h"

//44ms, 97.70%
//к╚об╠Й

class Solution {
public:
	bool isSubsequence(string s, string t) {
		int sloc = 0;
		int tloc = 0;
		int sSize = s.size();
		int tSize = t.size();

		while (sloc < sSize && tloc < tSize)
		{
			if (t[tloc] == s[sloc])
			{
				tloc++;
				sloc++;
			}
			else tloc++;
		}
		if (sloc == sSize) return true;
		else return false;
	}
};
