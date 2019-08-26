#include "public.h"

//12ms, 51.61%
//“ª±È…®√Ë

class Solution {
public:
	string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
		int sloc = 0;
		string res = "";
		while (sloc < S.size())
		{
			vector<int>::iterator iter = find(indexes.begin(), indexes.end(), sloc);
			if (iter != indexes.end())
			{
				int absi = iter - indexes.begin();
				if (S.substr(sloc, sources[absi].size()) == sources[absi])
				{
					res += targets[absi];
					sloc += sources[absi].size();
				}
				else
				{
					res.push_back(S[sloc]);
					sloc++;
				}
			}
			else
			{
				res.push_back(S[sloc]);
				sloc++;
			}
		}

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	string S = "vmokgggqzp";
	vector<int> indexes = { 3,5,1 };
	vector<string> sources = { "kg","ggq","mo" };
	vector<string> targets = { "s","so","bfr" };
	auto res = s->findReplaceString(S, indexes, sources, targets);
	return 0;
}
*/
