#include "public.h"

//0ms, 100%
//Ä£Äâ

class Solution {
public:
	bool backspaceCompare(string S, string T) {
		string ress;
		string rest;

		for (int i = 0; i < S.size(); ++i)
		{
			if (S[i] == '#')
			{
				if (!ress.empty()) ress.pop_back();
			}
			else ress.push_back(S[i]);
		}

		for (int i = 0; i < T.size(); ++i)
		{
			if (T[i] == '#')
			{
				if (!rest.empty()) rest.pop_back();
			}
			else rest.push_back(T[i]);
		}
		return ress == rest;
	}
};
