#include "public.h"

//
//Ä£Äâ

class Solution {
public:
	int maxNumberOfBalloons(string text) {
		unordered_map<char, int> count;

		for (auto& iter_text : text)
		{
			count[iter_text]++;
		}

		int res = INT_MAX;
		res = min(res, count['a']);
		res = min(res, count['b']);
		res = min(res, count['l'] / 2);
		res = min(res, count['o'] / 2);
		res = min(res, count['n']);

		return res;
	}
};
