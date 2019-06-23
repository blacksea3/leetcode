#include "public.h"

//DP problem, 20ms, 94.09%
//dp[row][col]: 如果这个元素是某个正方形的右下角, 那么这代表这个正方形的边长

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int rows = matrix.size();
		if (rows == 0) return 0;
		int columns = matrix[0].size();
		if (columns == 0) return 0;

		int res = 0;
		vector<vector<int>> dp(rows, vector<int>(columns, 0));
		//init
		for (int col = 0; col < columns; ++col)
		{
			if (matrix[0][col] == '1')
			{
				dp[0][col] = 1;
				res = max(res, 1);
			}
			else dp[0][col] = 0;
		}

		//主循环
		for (int row = 1; row < rows; ++row)
		{
			if (matrix[row][0] == '1')
			{
				dp[row][0] = 1;
				res = max(res, 1);
			}
			else dp[row][0] = 0;
			for (int col = 1; col < columns; ++col)
			{
				if (matrix[row][col] == '1')
				{
					dp[row][col] = min(dp[row - 1][col - 1], min(dp[row - 1][col], dp[row][col - 1])) + 1;
					res = max(res, dp[row][col] * dp[row][col]);
				}
				else
				{
					dp[row][col] = 0;
				}
			}
		}
		return res;
	}
};
