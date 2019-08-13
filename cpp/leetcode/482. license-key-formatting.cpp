#include "public.h"

//16ms, 72.89%
//倒过来遍历S即可

class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		deque<char> res;

		int precount = 0;

		for (int loc = S.size() - 1; loc >= 0; --loc)
		{
			if (S[loc] != '-')
			{
				if (precount == K)
				{
					res.push_front('-');
					precount = 1;
				}
				else precount++;
				if (S[loc] <= 'z' && S[loc] >= 'a') res.push_front(S[loc] - 'a' + 'A');
				else res.push_front(S[loc]);
			}
			else continue;
		}
		if (res[0] == '-') res.pop_front();

		string resstr;

		for (auto& iter_res : res) resstr.push_back(iter_res);
		return resstr;
	}
};
