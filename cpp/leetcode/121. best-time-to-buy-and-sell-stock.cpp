#include "public.h"

//8ms, 95.52%

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//一遍遍历,记住从下标1开始的所有元素之前的最小元素并且与当前元素比较即可
		int res = 0;
		int premin = INT_MAX;
		for (int i = 1; i < prices.size(); i++)
		{
			premin = min(premin, prices[i - 1]);
			res = max(res, prices[i] - premin);
		}
		return res;
	}
};
