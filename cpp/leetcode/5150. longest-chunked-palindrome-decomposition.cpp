#include "public.h"

//
//Ã∞¿∑, ¥”¡Ω±ﬂ’“

class Solution {
public:
	int longestDecomposition(string text) {
		int res = 0;

		int prelen = 1;
		int lastlen = 0;
		int tsize = text.size();
		bool even = false;
		while ((lastlen + prelen) <= tsize / 2)
		{
			if (text.substr(lastlen, prelen) == text.substr(tsize - lastlen - prelen, prelen))
			{
				if ((tsize % 2 == 0) && (lastlen + prelen) == tsize / 2) even = true;
				res += 2;
				lastlen += prelen;
				prelen = 1;
			}
			else prelen++;
		}
		if (!even) res++;
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->longestDecomposition("ghiabcdefhelloadamhelloabcdefghi");
	return 0;
}
*/
