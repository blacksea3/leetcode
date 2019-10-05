#include "public.h"

//0ms, 100%
//Ä£Äâ

class Solution {
public:
	int countSegments(string s) {
		bool isWord = false;
		int sSize = s.size();
		int res = 0;

		for (auto& iters : s)
		{
			if (iters == ' ')
			{
				if (isWord)
				{
					res++;
					isWord = false;
				}
			}
			else
			{
				if (!isWord) isWord = true;
			}
		}
		return isWord ? res + 1 : res;
	}
};
