#include "public.h"

//68ms, 5.81%
//把每一个有效括号的最外层括号都删掉

class Solution {
public:
	string removeOuterParentheses(string S) {
		int left = 0;

		int loc = 0;
		while (loc < S.size())
		{
			if (left == 0)
			{
				S.erase(S.begin() + loc);
				left++;
			}
			else
			{
				if (S[loc] == '(')
				{
					left++;
					loc++;
				}
				else
				{
					left--;
					if (left != 0) loc++;
					else S.erase(S.begin() + loc);
				}
			}
		}
	}
};

