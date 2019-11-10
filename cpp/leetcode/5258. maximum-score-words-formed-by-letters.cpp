#include "public.h"

//
//»ØËÝ?

class Solution {
private:
	int bigscore;

	pair<int, vector<int>> mscore(const string word, const vector<int>& let, const vector<int> sc)
	{
		int res = 0;
		vector<int> cplet = let;
		for (auto& iterword : word)
		{
			if (cplet[iterword - 'a'] > 0)
			{
				cplet[iterword - 'a']--;
				res += sc[iterword - 'a'];
			}
			else return pair<int, vector<int>>{-1, vector<int>{}};
		}
		return pair<int, vector<int>>{res, cplet};
	}

	void recu(const vector<string>& words, int hisw, int hisscore, vector<int>& let, const vector<int> sc)
	{
		bigscore = max(bigscore, hisscore);
		int wSize = words.size();
		vector<int> mem = let;
		for (int i = hisw + 1; i < wSize; ++i)
		{
			pair<int, vector<int>> preres = mscore(words[i], let, sc);
			if (preres.first != -1)
			{
				let = preres.second;
				recu(words, i, hisscore + preres.first, let, sc);
				let = mem;
			}
		}
	}

public:
	int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
		vector<int> let(26, 0);
		for (auto& ile : letters) let[ile - 'a']++;

		bigscore = 0;
		recu(words, -1, 0, let, score);
		return bigscore;
	}
};
