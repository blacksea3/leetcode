#include "public.h"

//100ms, 38.22%
//simple solution

class Solution {
public:
	string removeDuplicates(string S) {
		int left = 0;
		if (S.size() <= 1) return S;

		while ((left + 1) < S.size())
		{
			if (S[left] == S[left + 1])
			{
				S.erase(S.begin() + left);
				S.erase(S.begin() + left);
				if (left != 0) left--;
			}
			else
				left++;
		}
		return S;
	}
};
