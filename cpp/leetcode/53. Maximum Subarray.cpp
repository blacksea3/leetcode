#include "public.h"

//8ms, 88.94%
//暴力, 一轮扫描, 如果当前结果为正则与最终结果比较/更新, 为负则下一个重新开始
//注意: 涉及到了对输入nums的修改

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int res = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			nums[i] = max(nums[i-1] + nums[i], nums[i]);
			res = max(nums[i], res);
		}
		return res;
	}
};
