#include "public.h"

//
//ͳ������ż������

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
