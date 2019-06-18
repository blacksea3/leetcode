#include "public.h"

//12ms, 85.41%

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//只要后一天比前一天价格高,就卖出
		int res = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] > prices[i - 1]) res += (prices[i] - prices[i - 1]);
		}
		return res;
	}
};
