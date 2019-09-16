#include "public.h"

//8ms, 87.38%
//一遍遍历,记住从下标1开始的所有元素之前的最小元素并且与当前元素比较即可
//注意：尽管代码中貌似与当前元素比较的元素可能还有自身，但不影响结果

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		
		int res = 0;
		int premin = INT_MAX;
		for (int i = 0; i < prices.size(); i++)
		{
			premin = min(premin, prices[i]);
			res = max(res, prices[i] - premin);
		}
		return res;
	}
};
