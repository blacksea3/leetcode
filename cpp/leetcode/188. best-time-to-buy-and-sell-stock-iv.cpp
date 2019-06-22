#include "public.h"

//DP problem, 8ms, 96.77%

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		//Ūһ���޴��dp
		//dp[i][j]
		// 0 <= i < prices.size()
		// 0 <= j <= 2*k,  jΪż��:��ʾĿǰδ�ֲ�, jΪ������ʾĿǰ�ֲ�, (j+1)/2 ��ʾ������ǰ,�ѽ��е���������
		//����: j = 1��2 ��ʾ��ǰ�ǵ�һ������
		// k���=0 ,����0

		//ע�������������ڴ�ᱬ
		//����Ҫ����ĳһ�������Ϳ�����
		//��˲���Ҫi���ά��

		//ע��k,��Ч��k�����ܱ�prices.size() - 1��Ҫ��
		//����ע��,k >= prices.size()/2ʱ,����̰�ķ���,���Խ�ʡʱ��,����ʱ��ᱬ
		//������Ϊ,ֻҪ�������۹ɼ���α仯,ֻ��Ҫ��������Ϳ�����

		if (k == 0) return 0;
		if (prices.size() == 1) return 0;

		//����k
		if (k >= prices.size() / 2)
		{
			int res = 0;
			int old = INT_MAX;
			for (auto price : prices)
			{
				if (price > old) res += price - old;
				old = price;
			}
			return res;
		}
		else
		{
			vector<int> dp(2 * k + 1, 0);

			//����ǰ�����зǷ����,��ʵ���ϲ�Ҫ��:)  (����ͳ�������������,��������û�д���)
			for (int j = 0; j < k; j++)
				dp[2 * j + 1] = -1 * prices[0];

			for (int i = 1; i < prices.size(); i++)
			{
				for (int j = 0; j < k; j++)
				{
					dp[2 * j + 1] = max(dp[2 * j] - prices[i], dp[2 * j + 1]);
					dp[2 * j + 2] = max(dp[2 * j + 1] + prices[i], dp[2 * j + 2]);
				}
			}

			//Ŀǰδ�ֲֵ����ֵ
			int res = 0;
			for (int j = 0; j <= k; j++)
				res = max(dp[2 * j], res);

			return res;
		}
	}
};
