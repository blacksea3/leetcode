#include "public.h"

//12ms, 85.41%

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//ֻҪ��һ���ǰһ��۸��,������
		int res = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] > prices[i - 1]) res += (prices[i] - prices[i - 1]);
		}
		return res;
	}
};
