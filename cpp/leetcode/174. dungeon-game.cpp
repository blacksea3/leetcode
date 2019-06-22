#include "public.h"

//DP problem, 8ms, 94.18%
//dp[i][j]:从i,j到达右下角的最低初始健康指数
//从右下角向左上角更新
//右下角值初始化：若正则1否则取反加1
//各个位置更新值：举个例子
//dp[i][n - 1] = (dungeon[i][n - 1] >= dp[i + 1][n - 1]) ? 1 : (dp[i + 1][n - 1] - dungeon[i][n - 1]);
//更新时若有多个后置位置，则按照最低的要求血量效果来

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		//假设dungeon不为空
		int m = dungeon.size();     //row
		int n = dungeon[0].size();  //column

		vector<vector<int>> dp(m, vector<int>(n, 0));

		dp[m - 1][n - 1] = (dungeon[m - 1][n - 1] > 0) ? 1 : -1 * dungeon[m - 1][n - 1] + 1;
		for (int i = m - 2; i >= 0; i--)
			dp[i][n - 1] = (dungeon[i][n - 1] >= dp[i + 1][n - 1]) ? 1 : (dp[i + 1][n - 1] - dungeon[i][n - 1]);
		for (int j = n - 2; j >= 0; j--)
			dp[m - 1][j] = (dungeon[m - 1][j] >= dp[m - 1][j + 1]) ? 1 : (dp[m - 1][j + 1] - dungeon[m - 1][j]);

		for (int i = m - 2; i >= 0; i--)
		{
			for (int j = n - 2; j >= 0; j--)
			{
				dp[i][j] = min((dungeon[i][j] >= dp[i + 1][j]) ? 1 : (dp[i + 1][j] - dungeon[i][j]),
					(dungeon[i][j] >= dp[i][j + 1]) ? 1 : (dp[i][j + 1] - dungeon[i][j])
				);
			}
		}

		return dp[0][0];

	}
};
