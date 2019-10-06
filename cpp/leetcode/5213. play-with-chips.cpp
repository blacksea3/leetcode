#include "public.h"

//
//统计奇数偶数次数

class Solution {
public:
	int minCostToMoveChips(vector<int>& chips) {
		int odd = 0;
		int even = 0;
		for (auto& chip : chips)
		{
			if (chip % 2 == 0) even++;
			else odd++;
		}

		return min(even, odd);
	}
};
