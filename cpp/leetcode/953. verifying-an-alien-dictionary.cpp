#include "public.h"

//4ms, 99.58%
//将order转成unordered_map<char, int> 一个字母对一个数字,
//然后对words挨个判断

class Solution {
private:
	unordered_map<char, int> um;
	bool msort(const string& s1, const string& s2)
	{
		int loc = 0;
		while (loc < s1.size() && loc < s2.size())
		{
			if (um[s1[loc]] > um[s2[loc]]) return false;
			else if (um[s1[loc]] < um[s2[loc]]) return true;
			else loc++;
		}
		return loc == s1.size();
	}

public:
	bool isAlienSorted(vector<string>& words, string order) {
		for (int i = 0; i < order.size(); ++i)
			um[order[i]] = i;
		for (int i = 0; i < words.size() - 1; ++i)
			if (!msort(words[i], words[i + 1])) return false;
		return true;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<string> words = { "hello","leetcode" };
	cout << s->isAlienSorted(words, "hlabcdefgijkmnopqrstuvwxyz");
	return 0;
}
*/
