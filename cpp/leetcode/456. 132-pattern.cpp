#include "public.h"

//20ms, 99.04%
//单调栈
//从最右侧找大的元素们, 如果有更大的, 则入栈, 同时记录次大元素, 如果有比次大元素小的则ok

class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		stack<int> rightmax;
		int third = INT_MIN;

		for (int i = nums.size() - 1; i >= 0; --i)
		{
			if (nums[i] < third) return true;
			while (!rightmax.empty() && nums[i] > rightmax.top())
			{
				third = rightmax.top();
				rightmax.pop();
			}
			rightmax.push(nums[i]);
		}
		return false;
	}
};
