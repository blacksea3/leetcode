#include "public.h"

//16ms, 52.47%
//“ª¬÷…®√Ë

class Solution {
public:
	vector<vector<int>> largeGroupPositions(string S) {
		vector<vector<int>> res;

		int preloc = 1;
		int oldchar = S[0];
		int oldlen = 1;
		int oldloc = 0;
		while (preloc < S.size())
		{
			if (S[preloc] == oldchar)
			{
				oldlen++;
			}
			else
			{
				if (oldlen >= 3)
				{
					res.push_back({ oldloc, preloc - 1 });
				}
				oldlen = 1;
				oldchar = S[preloc];
				oldloc = preloc;
			}
			preloc++;
		}
		if (oldlen >= 3)
		{
			res.push_back({ oldloc, preloc - 1 });
		}
		return res;
	}
};
