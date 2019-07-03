#include "public.h"

//ע�ⶼ��������, ����û���ظ�����!, ����Ҳ��������!
//dp[i] iʱ����ϸ���
//��ôdp[������]=nums�еĸ�����+dp[С����]

//ע���������:nums={3,33,333}, target =10000, �����0, ����ֱ��������, ������dp[i]>INT_MAXһ��

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<long> dp(target + 1, 0);
		//��ʼ��dp[0]=1
		dp[0] = 1;
		for (int i = 1; i <= target; ++i)
		{
			for (auto& n : nums)
				if (i - n >= 0)
				{
					dp[i] += dp[i - n];
					if (dp[i] > INT_MAX) break;
				}
		}
		return dp[target];
	}
};

