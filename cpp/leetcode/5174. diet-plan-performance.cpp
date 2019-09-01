#include "public.h"

//
//滑动窗口

class Solution {
private:
	int mark(int sum, int low, int up)
	{
		if (sum < low) return -1;
		else if (sum > up) return 1;
		else return 0;
	}

public:
	int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
		int preSum = 0;
		//init
		for (int index = 0; index < k; ++index)
		{
			preSum += calories[index];
		}
		int res = 0;
		res += mark(preSum, lower, upper);

		//主滑动窗口
		for (int index = k; index < calories.size(); ++index)
		{
			preSum -= calories[index - k];
			preSum += calories[index];
			res += mark(preSum, lower, upper);
		}
		return res;
	}
};
