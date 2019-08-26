#include "public.h"

//20ms, 57.83%
//DFS, ееап

class Solution {
private:
	vector<string> res;
	void DFS(const string& S, int preloc, string prestr)
	{
		if (preloc == S.size()) res.push_back(prestr);
		else
		{
			if (S[preloc] <= 'z' && S[preloc] >= 'a')
			{
				prestr.push_back(S[preloc]);
				DFS(S, preloc + 1, prestr);
				prestr.pop_back();
				prestr.push_back(S[preloc] - 'a' + 'A');
				DFS(S, preloc + 1, prestr);
			}
			else if (S[preloc] <= 'Z' && S[preloc] >= 'A')
			{
				prestr.push_back(S[preloc]);
				DFS(S, preloc + 1, prestr);
				prestr.pop_back();
				prestr.push_back(S[preloc] - 'A' + 'a');
				DFS(S, preloc + 1, prestr);
			}
			else
			{
				prestr.push_back(S[preloc]);
				DFS(S, preloc + 1, prestr);
			}
		}
	}

public:
	vector<string> letterCasePermutation(string S) {
		DFS(S, 0, "");
		return res;
	}
};
