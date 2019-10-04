#include "public.h"

//0ms, 100%
//多种情况:
//见代码, 滑动窗口, 来源于https://leetcode-cn.com/problems/self-crossing/solution/335lu-jing-jiao-cha-by-zhangll/

class Solution {
public:
	bool isSelfCrossing(vector<int>& x) {
		for (int i = 3; i < (int)x.size(); ++i)
		{
			if (i >= 3)
			{
				if ((x[i] >= x[i - 2]) && (x[i - 1] <= x[i - 3])) return true;
			}
			if (i > 3)
			{
				if ((x[i - 3] == x[i - 1]) && ((x[i - 4] + x[i]) == x[i - 2])) return true;
			}
			if (i > 4)
			{
				if (((x[i - 3] - x[i - 5]) <= x[i - 1]) && (x[i - 1] <= x[i - 3]) &&
					(x[i - 2] - x[i - 4]) <= x[i] && (x[i] <= x[i - 2]) && (x[i - 2] >= x[i - 4]))
					return true;
			}
		}
		return false;
	}
};
