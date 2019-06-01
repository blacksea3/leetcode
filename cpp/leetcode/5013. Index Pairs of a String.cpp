#include "public.h"

class Solution {
private:
	static bool mcompare(string a, string b)
	{
		return a.size() <= b.size();
	}
private: 
	void msort(vector<string>& words)
	{
		for (int i = 0; i < words.size() - 1; i++)
		{
			for (int j = i + 1; j < words.size(); j++)
			{
				if (words[i].size() > words[j].size())
				{
					string temp = words[i];
					words[i] = words[j];
					words[j] = temp;
				}
			}
		}
	}

public:
	vector<vector<int>> indexPairs(string text, vector<string>& words) {


		//brute force
		vector<vector<int>> re = {};

		//sort words.length..
		//sort(words.begin(), words.end(), mcompare);

		msort(words);
		int tlen = text.size();

		for (int i = 0; i < tlen; ++i)
		{
			for (auto w : words)
			{
				if (text.substr(i, w.size()) == w)
					re.push_back(vector<int> {i, (int)w.size() + i - 1});
			}
		}
		return re;
	}
};

/*
int main() {
	Solution* s = new Solution();
	vector<string> words = { "ababaaabb", "babbabaa", "aaabbaaaab", "babbbba", "bbbbaabbabb", "aaaabbbaaaaa", "bbbbaabb", "abbabbabba", "abbabbbabaab", "abbaaabba", "aabaaabbabab", "aaaabaa", "abbbabbba", "bababbaba", "aabaabb", "babbabbbbbaa", "bbabbaa", "abaaabaabaaa", "baaabaaaabaa", "aabbababaaaa" };
	vector<vector<int>> res = s->indexPairs("aabbaababbabaababbaaababbbbbab", words);

	return 0;
}
*/
