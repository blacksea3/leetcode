#include "public.h"

//count chars, 4ms, 86.73%

//then use this rule: if one char occur, while (the last char in returnstr > prechar and the last char 
//  will ouucr latter(use the count res), remove the last char), after the while, add this new char

class Solution {
public:
	string smallestSubsequence(string text) {
		unordered_map<char, int> um;
		for (auto t : text) um[t]++;
		string ress = "";
		set<char> visited;

		for (auto t : text)
		{
			if (visited.find(t) != visited.end())
			{
				um[t]--;
				continue;
			}
			else
			{
				while ((!ress.empty()) && (t < ress[ress.size() - 1]) && (um[ress[ress.size() - 1]] > 0))
				{
					visited.erase(ress[ress.size() - 1]);
					ress.pop_back();
				}
				um[t]--;
				visited.insert(t);
				ress.push_back(t);
			}
		}
		return ress;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	string res = s->smallestSubsequence("cdadabcc");
	return 0;
}
*/