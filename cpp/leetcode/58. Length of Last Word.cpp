#include "public.h"

//8ms, 92.71%

//brute force
//note: here if i >= s.size(), s[i] is just 0

class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = 0, i = 0;
		while (s[i]) {
			if (s[i++] != ' ')
				++len;
			else if (s[i] && s[i] != ' ')
				len = 0;
		}
		return len;
	}
};