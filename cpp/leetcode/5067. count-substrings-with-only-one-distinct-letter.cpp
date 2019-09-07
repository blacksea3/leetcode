#include "public.h"

//
//假设个数不会越界

class Solution {
public:
	int countLetters(string S) {
		int res = 0;
		int preLen = 1;
		char oldCh = S[0];

		for (int index = 1; index < S.size(); ++index)
		{
			if (S[index] != oldCh)
			{
				res += (preLen)*(preLen + 1) / 2;
				oldCh = S[index];
				preLen = 1;
			}
			else
				preLen++;
		}
		res += (preLen)*(preLen + 1) / 2;
		return res;
	}
};
