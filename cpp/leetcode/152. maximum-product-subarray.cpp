#include "public.h"

//4ms, 98.18%

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		//存放当前的最大值和最小值
		//如果遇到0,当前最大值和最小值都等于0
		//如果遇到正数,扩展
		//如果遇到负数,交换
		int res = INT_MIN;
		int smax = 1;
		int smin = 1;
		for (auto num : nums)
		{
			if (num < 0) swap(smax, smin); //交换
			smax = max(smax*num, num);
			smin = min(smin*num, num);
			res = max(res, smax);
		}
		return res;
	}
};
