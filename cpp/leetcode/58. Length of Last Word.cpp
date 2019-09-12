#include "public.h"

//4ms, 86.55%
//±©Á¦, µ¹Ğò±éÀú

class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = 0, index = s.size() - 1;
		while (index >= 0) {
			if (s[index--] != ' ')
				++len;
			else if (len != 0)
				return len;
		}
		return len;
	}
};
