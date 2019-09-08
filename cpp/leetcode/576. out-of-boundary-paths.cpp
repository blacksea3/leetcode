#include "public.h"

//20ms, 69.79%
//dp
//按次数迭代
//dp[i][j] 表示移动到当前格

class Solution {
private:
	const int MOD = 1000000007;
public:
	int findPaths(int m, int n, int N, int i, int j) {
		long long res = 0;
		vector<vector<long long>> dp(m, vector<long long>(n, 0));
		dp[i][j] = 1;

		for (int time = 0; time < N; ++time)
		{
			vector<vector<long long>> temp(m, vector<long long>(n, 0));
			//界内数目更新
			for (int r = 0; r < m; ++r)
			{
				for (int c = 0; c < n; ++c)
				{
					long long pre = 0;
					if (r > 0) pre += dp[r - 1][c];
					if (c > 0) pre += dp[r][c - 1];
					if (r < m - 1) pre += dp[r + 1][c];
					if (c < n - 1) pre += dp[r][c + 1];
					temp[r][c] = pre % MOD;
				}
			}
			//出界数更新
			//只有一行
			if (m == 1)
			{
				for (int c = 0; c < n; ++c)
				{
					res += 2 * dp[0][c];
				}
				if (n != 1) res += (dp[0][0] + dp[0][n - 1]);
				else res += 2 * dp[0][0];
				res %= MOD;
			}
			else if (n == 1) //只有一列
			{
				for (int r = 0; r < m; ++r)
				{
					res += 2 * dp[r][0];
				}
				res += (dp[0][0] + dp[m - 1][0]);
				res %= MOD;
			}
			else
			{
				for (int c = 0; c < n; ++c)
				{
					res += dp[0][c];
					res += dp[m - 1][c];
				}
				for (int r = 0; r < m; ++r)
				{
					res += dp[r][0];
					res += dp[r][n - 1];
				}
				res %= MOD;
			}
			dp = temp;
		}
		return (int)res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->findPaths(8, 50, 23, 5, 26);
	return 0;
}
*/
