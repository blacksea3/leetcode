#include "public.h"

//DP problem, 8ms, 96.77%

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		//弄一个巨大的dp
		//dp[i][j]
		// 0 <= i < prices.size()
		// 0 <= j <= 2*k,  j为偶数:表示目前未持仓, j为奇数表示目前持仓, (j+1)/2 表示包括当前,已进行的买卖轮数
		//例如: j = 1与2 表示当前是第一轮买卖
		// k如果=0 ,返回0

		//注意上述的做法内存会爆
		//仅需要保存某一天的利润就可以了
		//因此不需要i这个维度

		//注意k,有效的k不可能比prices.size() - 1还要大
		//另外注意,k >= prices.size()/2时,采用贪心方法,可以节省时间,否则时间会爆
		//这是因为,只要这样无论股价如何变化,只需要低买高卖就可以了

		if (k == 0) return 0;
		if (prices.size() == 1) return 0;

		//操作k
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

			//可能前几天有非法情况,这实际上不要紧:)  (就是统计买卖轮数错掉,但是利润没有错噢)
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

			//目前未持仓的最大值
			int res = 0;
			for (int j = 0; j <= k; j++)
				res = max(dp[2 * j], res);

			return res;
		}
	}
};
