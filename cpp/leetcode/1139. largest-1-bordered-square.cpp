#include "public.h"

//128ms, 9.49%
//����dp[i][j][0]/[1]/[2]/[3] ��ʾ������:�������µĴ�����(i,j)��ʼ������1�ĸ���(���Լ���ʼ)
//Ȼ�����dp, 

class Solution {
public:
	int largest1BorderedSquare(vector<vector<int>>& grid) {
		vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(4, 0)));

		for (int r = 0; r < grid.size(); ++r)
		{
			int left = -1;
			int c = 0;
			while (c < grid[0].size())
			{
				if (grid[r][c] == 1)
				{
					left = c;
					while (c < grid[0].size() && grid[r][c] == 1) c++;
					int right = c - 1;
					int time = 1;
					while (left + time - 1 <= right)
					{
						dp[r][left + time - 1][0] = time;
						time++;
					}
					time = 1;
					while ((time >= 1) && (right - time + 1 >= left))
					{
						dp[r][right - time + 1][1] = time;
						time++;
					}
				}
				else c++;
			}
		}

		for (int c = 0; c < grid[0].size(); ++c)
		{
			int top = -1;
			int r = 0;
			while (r < grid.size())
			{
				if (grid[r][c] == 1)
				{
					top = r;
					while (r < grid.size() && grid[r][c] == 1) r++;
					int down = r - 1;
					int time = 1;
					while (top + time - 1 <= down)
					{
						dp[top + time - 1][c][2] = time;
						time++;
					}
					time = 1;
					while ((time >= 1) && (down - time + 1 >= top))
					{
						dp[down - time + 1][c][3] = time;
						time++;
					}
				}
				else r++;
			}
		}

		//����ͳ��������
		int res = 0;

		for (int r = 0; r < grid.size(); ++r)
		{
			for (int cl = 0; cl < grid[0].size(); ++cl)
			{
				for (int cr = cl; cr < grid[0].size(); ++cr)
				{
					int downr = r + (cr - cl);
					if (downr >= grid.size()) break;
					int len = cr - cl + 1;
					if ((dp[r][cl][1] >= len) && (dp[r][cr][0] >= len) && (dp[r][cl][3] >= len) && (dp[r][cr][3] >= len) &&
						(dp[downr][cl][1] >= len) && (dp[downr][cr][0] >= len) && (dp[downr][cl][2] >= len) && (dp[downr][cr][2] >= len)
						)
						res = max(res, len);
				}
			}
		}
		return res * res;
	}
};
