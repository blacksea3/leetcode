#include "public.h"

//20ms, 7.43%
//dp[i]生效到第i天的最低消费
//if i not in days, dp[i] = dp[i-1]
//else: dp[i] = dp[i-1] + 1天消费/ dp[i-7] + 7天消费/ dp[i-30] + 30天消费 的最小值

class Solution {
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		vector<int> dp(366, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= 365; ++i)
		{
			if (find(days.begin(), days.end(), i) == days.end())
			{
				dp[i] = dp[i - 1];
			}
			else
			{
				dp[i] = min(dp[i], dp[i - 1] + costs[0]);
				for (int j = 1; j <= min(i, 7); ++j)
				{
					dp[i] = min(dp[i], dp[i - j] + costs[1]);
				}
				for (int j = 1; j <= min(i, 30); ++j)
				{
					dp[i] = min(dp[i], dp[i - j] + costs[2]);
				}
			}
		}
		return dp[days[days.size() - 1]];
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<int> days = { 1,4,6,7,8,20 };
	//vector<int> costs = { 2,7,15 };
	//auto res = s->mincostTickets(days, costs);

	//vector<int> days = { 1,4,6,7,8,20 };
	//vector<int> costs = { 7,2,15 };
	//auto res = s->mincostTickets(days, costs);

	vector<int> days = { 1, 2, 3, 4, 6, 8, 9, 10, 13, 14, 16, 17, 19, 21, 24, 26, 27, 28, 29 };
	vector<int> costs = { 3, 14, 50 };
	auto res = s->mincostTickets(days, costs);
	return 0;
}
*/
