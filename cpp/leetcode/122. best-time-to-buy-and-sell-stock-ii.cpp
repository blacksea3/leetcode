#include "public.h"

//8ms, 85.28%
//ֻҪ��һ���ǰһ��۸��,������

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		
		int res = 0;
		for (int i = 1, i_m1 = 0; i < prices.size(); i++, i_m1++)
		{
			res += max(0, prices[i] - prices[i_m1]);
		}
		return res;
	}
};
