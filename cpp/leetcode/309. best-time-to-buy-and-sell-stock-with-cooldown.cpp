#include "public.h"

//4ms, 93.19%
//DP problem
//����״̬: �������: ����/����/��ȴ
//����: ��һ������=max(����, ����-�۸�), ��һ����ȴ=����+�۸�, ��һ������=max(����, ��ȴ)

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (!prices.size()) return 0;

		int buy = -1 * prices[0];
		int colddown = 0;
		int canbuy = 0;

		for (int i = 1; i < prices.size(); ++i)
		{
			int old_canbuy = canbuy;
			canbuy = max(canbuy, colddown);
			colddown = buy + prices[i];
			buy = max(buy, old_canbuy - prices[i]);
		}
		return max(colddown, canbuy);
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> prices = { 1,2,3,0,2 };
	cout << s->maxProfit(prices);
	return 0;
}
*/
