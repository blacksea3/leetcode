#include "public.h"

//8ms, 54.77%
//¿¼ÂÇ±ß½ç, ±©Á¦ÅÐ¶Ï

class Solution {
private:
	bool isSelfDividingNumber(int val)
	{
		int cpVal = val;
		while (cpVal > 0)
		{
			if ((cpVal % 10 == 0) || (val % (cpVal % 10) != 0))
				return false;
			cpVal /= 10;
		}
		return true;
	}

public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> res;
		for (int num = left; num <= right; ++num)
		{
			if (isSelfDividingNumber(num))
				res.push_back(num);
		}
		return res;
	}
};
