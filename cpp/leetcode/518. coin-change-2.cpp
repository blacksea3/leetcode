#include "public.h"

//20ms, 45.31%
//dp[i] ��ʾ�ճ�i��Ӳ�������
//��ʼ��dp[0] = 1
//����, ��Ӳ�ҽ�����, ��ѭ����������, ��Ľ��dp[i + n] += С�Ľ��dp[i], nΪ��ǰ���
//ע��:����ĳ����϶����ͬӲ��, ȫ����ĳһ����ѭ�������
//����:��Ϊ�ǰ�Ӳ�ҽ�����ѭ����, �������ظ���������
//����dp[amount]

class Solution {
public:
	int change(int amount, vector<int>& coins) {
		vector<int> dp(amount + 1, 0);
		dp[0] = 1;

		for (auto& coin : coins)
		{
			for (int val = coin; val <= amount; ++val)
			{
				dp[val] += dp[val - coin];
			}
		}
		return dp[amount];
	}
};
