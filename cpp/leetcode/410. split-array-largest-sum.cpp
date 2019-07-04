#include "public.h"

//268ms, 15.66%
//定义dp[i][j]为从前开始数达到下标为i-1的时候, nums内的数被分割成j份的最小的最大值
//仅初始化dp[0][0]=0, 其他dp[?][0] = INT_MAX, dp[0][?] = INT_MAX
//那么dp[i][j] = min(max(dp[k][j-1], nums[k]+...+nums[i-1]), ..0 < k < i)

class Solution {
public:
	int splitArray(vector<int>& nums, int m) {
		int n = nums.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
		dp[0][0] = 0;

		vector<int> sub(n + 1, 0);
		for (int i = 0; i < n; i++) {
			sub[i + 1] = sub[i] + nums[i];
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= min(i,m); j++) {
				for (int k = 0; k < i; k++) {
					dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sub[i] - sub[k]));
				}
			}
		}
		return dp[n][m];
	}
};
