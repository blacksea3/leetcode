#include "public.h"

//8ms, 67.72%
//简朴的比较方法

class Solution {
private:
	bool isMatch(string que, string pat)
	{
		int qloc = 0;
		int ploc = 0;
		while (qloc < que.size() && ploc < pat.size())
		{
			if (que[qloc] == pat[ploc])
			{
				qloc++;
				ploc++;
			}
			else if (que[qloc] <= 'z' && que[qloc] >= 'a')
			{
				qloc++;
			}
			else return false;
		}

		if (ploc != pat.size()) return false;
		else
		{
			while (qloc < que.size())
			{
				if (que[qloc] <= 'z' && que[qloc] >= 'a')
				{
					qloc++;
				}
				else return false;
			}
			return true;
		}
	}

public:
	vector<bool> camelMatch(vector<string>& queries, string pattern) {
		vector<bool> res(queries.size());
		for (int i = 0; i < queries.size(); ++i)
			res[i] = isMatch(queries[i], pattern);
		return res;
	}
};
