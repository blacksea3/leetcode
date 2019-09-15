#include "public.h"

//0ms, 100%
//»ØËÝ

class Solution {
private:
	vector<string> res = {};
	void BackTrack(const string& s, const int& totalloc, int startloc, vector<string>& prestrs, int oldlen)
	{
		for (int i = max(totalloc - startloc - 3 * (3 - oldlen), 1); i <= min(totalloc - startloc - (3 - oldlen), 3); ++i)
		{
			string temps = s.substr(startloc, i);
			int tempi = stoi(temps);
			if ((tempi <= 255) && (tempi >= 0))
			{
				if ((i == 1) || (s.substr(startloc, i)[0] != '0'))
				{
					prestrs.push_back(temps);
					if (oldlen == 3)
					{
						string tres = prestrs[0];
						for (int k = 1; k <= 3; ++k)
						{
							tres += ".";
							tres += prestrs[k];
						}
						res.push_back(tres);
					}
					else BackTrack(s, totalloc, startloc + i, prestrs, oldlen + 1);
					prestrs.pop_back();
				}
			}
		}
	}

public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> prestrs;
		BackTrack(s, s.size(), 0, prestrs, 0);
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<string> res = s->restoreIpAddresses("25525511135");
	return 0;
}
*/
