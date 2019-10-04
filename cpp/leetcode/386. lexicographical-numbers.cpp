#include "public.h"

//88ms, 98.57%
//O(n)
//按顺序push_back
//数学题找规律 1,10,11,12,13,2,3,4,5,6,7,8,9

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
			res.emplace_back(i);
			add(i);
		}
	}

public:
	vector<int> lexicalOrder(int n) {
		gbln = n;
		for (int i = 1; i <= min(n, 9); ++i)
		{
			res.emplace_back(i);
			add(i);
		}
		return res;
	}
};
