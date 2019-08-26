#include "public.h"

//
//Ä£Äâ

class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		vector<int> countchars(26, 0);

		for (auto& iter_chars : chars)
		{
			countchars[iter_chars - 'a']++;
		}

		int res = 0;
		for (auto& word : words)
		{
			vector<int> inner_cont(26, 0);
			for (auto& iter_word : word)
			{
				inner_cont[iter_word - 'a']++;
			}

			bool flag = true;
			for (int i = 0; i < 26; ++i)
			{
				if (inner_cont[i] > countchars[i])
				{
					flag = false;
					break;
				}
			}
			if (flag) res += word.size();
		}
		return res;
	}
};

