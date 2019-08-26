#include "public.h"

//
//Ä£Äâ

class Solution {
public:
	int calculateTime(string keyboard, string word) {
		unordered_map<char, int> um;

		for (int index = 0; index < keyboard.size(); ++index)
		{
			um[keyboard[index]] = index;
		}

		int res = 0;
		res += um[word[0]];

		for (int index = 1; index < word.size(); ++index)
		{
			res += abs(um[word[index]] - um[word[index - 1]]);
		}

		return res;
	}
};
