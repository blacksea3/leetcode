#include "public.h"

//48ms, 97.87%
//近似暴力
//将words转成26位二进制

class Solution {
public:
	int maxProduct(vector<string>& words) {
		if (words.size() <= 1) return 0;

		vector<int> wsizes(words.size(), 0);
		vector<int> allwords(words.size(), 0);

		for (int i = 0; i < words.size(); ++i)
		{
			wsizes[i] = words[i].size();
			for (auto& c : words[i])
				allwords[i] |= 1 << (c - 'a');
		}

		//O(n^2)暴力
		int res = 0;
		for (int i = 0; i < words.size() - 1; ++i)
			for (int j = i + 1; j < words.size(); ++j)
				if ((allwords[i] & allwords[j]) == 0)
					res = max(wsizes[i] * wsizes[j], res);
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<string> words = { "abcw","baz","foo","bar","xtfn","abcdef" };
	vector<string> words = { "abcw"};
	cout << s->maxProduct(words);
	return 0;
}
*/
