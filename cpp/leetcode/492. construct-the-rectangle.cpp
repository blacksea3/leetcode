#include "public.h"

//8ms, 55.79%
//长是area的最小的, 大于等于sqrt(area)的因子
//那么宽就是area的最大的, 小于等于sqrt(area)的因子

class Solution {
public:
	vector<int> constructRectangle(int area) {
		for (int i = (int)sqrt(area); i >= 2; --i)
			if (area%i == 0) return { area / i, i };

		return { area, 1 };
	}
};
