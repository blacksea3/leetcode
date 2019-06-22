#include "public.h"

//simple solution, สýังฬโ, 4ms, 96.36%

class Solution {
public:
	int titleToNumber(string s) {
		int res = 0;
		for (auto is : s)
		{
			res *= 26;
			res += is - 'A' + 1;
		}
		return res;
	}
};
