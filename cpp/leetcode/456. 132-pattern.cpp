#include "public.h"

//20ms, 99.04%
//����ջ
//�����Ҳ��Ҵ��Ԫ����, ����и����, ����ջ, ͬʱ��¼�δ�Ԫ��, ����бȴδ�Ԫ��С����ok

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
