#include "public.h"

class Solution {
public:
	string smallestSubsequence(string text) {
		unordered_map<char, int> um;
		for (auto t : text) um[t]++;
		vector<char> resv = {};
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
				while ((!resv.empty()) && (t < resv[resv.size() - 1]) && (um[resv[resv.size() - 1]] > 0))
				{
					visited.erase(resv[resv.size() - 1]);
					resv.pop_back();
				}
				um[t]--;
				visited.insert(t);
				resv.push_back(t);
			}
		}
		string ress;
		for (auto r : resv)
			ress.push_back(r);

		
		return ress;
	}
};

int main()
{
	Solution* s = new Solution();
	string res = s->smallestSubsequence("cdadabcc");
	return 0;
}
