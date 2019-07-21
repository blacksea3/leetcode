#include "public.h"

//40ms, 84.19%
//按余数分类

class Solution {
public:
	int numPairsDivisibleBy60(vector<int>& time) {
		vector<int> remains(60, 0); //remain[i]: 余数为i的个数

		for (auto& t : time)
			remains[t % 60]++;

		int res = 0;

		for (int i = 1; i <= 29; ++i)
		{
			res += remains[i] * remains[60 - i];
		}

		res += (remains[0] * (remains[0] - 1)) / 2;
		res += (remains[30] * (remains[30] - 1)) / 2;
		return res;
	}
};
