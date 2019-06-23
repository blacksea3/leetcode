#include "public.h"

//DP problem, 连续两遍198题打家劫舍, 4ms, 91.29%

class Solution {
private:
	int rob_199(vector<int>& nums, int startloc, int endloc)
	{
		//dpi:偷窃开头直到包含i下标的最大金额
	//只保存最后三个dp
	//init
		int nsize = endloc - startloc + 1;

		if (nsize <= 0)
			return 0;
		else if (nsize == 1)
			return nums[startloc];
		else if (nsize == 2)
			return max(nums[startloc], nums[endloc]);
		else
		{
			int dp0 = nums[startloc];
			int dp1 = nums[startloc + 1];
			int dp2 = nums[startloc] + nums[startloc + 2];
			for (int i = startloc + 3; i <= endloc; i++)
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


public:
	int rob(vector<int>& nums) {
		//连续两遍198题
		if (nums.size() == 0) return 0;
		else if (nums.size() == 1) return nums[0];
		else return max(rob_199(nums, 0, nums.size() - 2), rob_199(nums, 1, nums.size() - 1));
	}
};
