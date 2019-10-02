#include "public.h"

//44ms, 71.18%
//DP problem
//O(n^2), �����Ͽ��Խ�϶��ֲ��ҽ���O(nlongn), ���Ż�
//����ĳ��λ��, dp[i]��ʾ�����������������г���
//����dp[i+1]ʱ����ǰ�������dp, ���ұȽ���������

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int nSize = nums.size();

		if (nSize == 0) return 0;
		else
		{
			vector<int> dp(nSize, 0);
			dp[0] = 1;

			for (int i = 1; i < nSize; ++i)
			{
				int premax = 0;
				for (int j = 0; j < i; ++j)
				{
					if (nums[j] < nums[i]) premax = max(premax, dp[j]);
				}
				dp[i] = premax + 1;
			}
			return *max_element(dp.begin(), dp.end());
		}
	}
};
