#include "public.h"

//DP problem, 0ms, 100%

class Solution {
public:
	int rob(vector<int>& nums) {
		//dpi:偷窃开头直到包含i下标的最大金额
		//只保存最后三个dp
		//init
		if (nums.size() == 0)
			return 0;
		else if (nums.size() == 1)
			return nums[0];
		else if (nums.size() == 2)
			return max(nums[0], nums[1]);
		else
		{
			int dp0 = nums[0];
			int dp1 = nums[1];
			int dp2 = nums[0] + nums[2];
			for (int i = 3; i < nums.size(); i++)
			{
				dp0 = max(dp0, dp1) + nums[i];
				int temp = dp0;
				dp0 = dp1;
				dp1 = dp2;
				dp2 = temp;
			}
			return max(dp1, dp2);
		}
	}
};