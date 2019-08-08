#include "public.h"

//16ms, 87.03%
//正着扫一遍, 倒着扫一遍

class Solution {
public:
	vector<int> shortestToChar(string S, char C) {
		int predis = 99999;
		vector<int> r1(S.size());
		vector<int> r2(S.size());

		for (int i = 0; i < S.size(); ++i)
		{
			if (S[i] == C) predis = 0;
			r1[i] = predis;
			predis++;
		}

		for (int i = S.size() - 1; i >= 0; --i)
		{
			if (S[i] == C) predis = 0;
			r2[i] = predis;
			predis++;
		}

		vector<int> res(S.size());
		for (int i = 0; i < S.size(); ++i)
			res[i] = min(r1[i], r2[i]);
		return res;
	}
};
