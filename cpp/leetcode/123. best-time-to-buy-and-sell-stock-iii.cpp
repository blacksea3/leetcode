#include "public.h"

//12ms, 72.77%
//dp����
//ֱ��ʹ�ÿռ��Ż���:��һ�������¼ĳһ�����п��ܲ����µ��������
//(0:��, 1����һ��, 2����һ��, 3����һ��Ȼ�����һ��, 4��������)���������(������Ǹ���, ���������ʱ)

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0) return 0;

		//����������ע��
		int dp0 = 0;
		int dp2 = 0;
		int dp4 = 0; 
		int dp1 = -1 * prices[0];
		int dp3 = -1 * prices[0];
		//����ǰ�����зǷ����,��ʵ���ϲ�Ҫ��:)
		for (int i = 1; i < prices.size(); i++)
		{
			//dp[i][0] = dp[i - 1][0];
			dp1 = max(dp1, dp0 - prices[i]);
			dp2 = max(dp2, dp1 + prices[i]);
			dp3 = max(dp3, dp2 - prices[i]);
			dp4 = max(dp4, dp3 + prices[i]);
		}

		return max(dp0, max(dp2, dp4));
	}
};
