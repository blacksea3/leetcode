#include "public.h"

//100ms, 98.04%
//O(n)
//°´Ë³Ðòpush_back

class Solution {
private:
	vector<int> res;
	int gbln;

	void add(int startnum)
	{
		startnum *= 10;
		for (int i = startnum; i <= startnum + 9; ++i)
		{
			if (i > gbln) return;
			res.push_back(i);
			add(i);
		}
	}

public:
	vector<int> lexicalOrder(int n) {
		gbln = n;
		for (int i = 1; i <= min(n, 9); ++i)
		{
			res.push_back(i);
			add(i);
		}
		return res;
	}
};
