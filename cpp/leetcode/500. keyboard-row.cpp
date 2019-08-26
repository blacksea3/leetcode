#include "public.h"

//8ms, 33.49%
//字母分组, 然后查看就行

class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		unordered_set<char> firstline = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p' };
		unordered_set<char> secondline = { 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l' };
		vector<string> res;

		for (auto& word : words)
		{
			string cpword = word;
			if (word[0] <= 'Z' && word[0] >= 'A') word[0] = word[0] - 'A' + 'a';
			int line = 0;
			if (firstline.find(word[0]) != firstline.end()) line = 1;
			else if (secondline.find(word[0]) != secondline.end()) line = 2;
			else line = 3;

			bool isgood = true;
			for (int loc = 1; loc < word.size(); ++loc)
			{
				if (word[loc] <= 'Z' && word[loc] >= 'A') word[loc] = word[loc] - 'A' + 'a';
				if ((line == 1 && firstline.find(word[loc]) == firstline.end()) ||
					(line == 2 && secondline.find(word[loc]) == secondline.end()) ||
					(line == 3 &&
					(firstline.find(word[loc]) != firstline.end() ||
						secondline.find(word[loc]) != secondline.end())
						)
					)
				{
					isgood = false;
					break;
				}
			}
			if (isgood) res.push_back(cpword);
		}
		return res;
	}
};
