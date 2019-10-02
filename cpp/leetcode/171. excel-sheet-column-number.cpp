#include "public.h"

//0ms, 100%
//สýัง

class Solution {
public:
	int titleToNumber(string s) {
		int res = 0;
		for (auto& is : s)
		{
			res *= 26;
			res += is - 'A' + 1;
		}
		return res;
	}
};
