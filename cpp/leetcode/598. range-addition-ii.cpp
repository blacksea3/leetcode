#include "public.h"

//4ms, 100%
//����ops����С��a �� b �ĳ˻�

class Solution {
public:
	int maxCount(int m, int n, vector<vector<int>>& ops) {
		if (ops.empty()) return m * n;

		int mina = INT_MAX;
		int minb = INT_MAX;

		for (auto& op : ops)
		{
			mina = min(mina, op[0]);
			minb = min(minb, op[1]);
		}
		return mina * minb;
	}
};
