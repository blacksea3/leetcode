#include "public.h"

//8ms, 88.94%
//����, һ��ɨ��, �����ǰ���Ϊ���������ս���Ƚ�/����, Ϊ������һ�����¿�ʼ
//ע��: �漰���˶�����nums���޸�

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
