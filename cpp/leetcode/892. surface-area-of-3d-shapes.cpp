#include "public.h"

//16ms, 45.39%
//ģ��:
//����: ����0�ĸ���
//��: �����������0, ��ÿ�μ���delta(��ǰ��-��߸�)
//��: �������ұ���0, ��ÿ�μ���delta(��ǰ��-�ұ߸�)
//ǰ��ͬ��

class Solution {
public:
	int surfaceArea(vector<vector<int>>& grid) {
		int res = 0;
		int rows = grid.size();
		int cols = grid[0].size();

		//����
		for (int r = 0; r < rows; ++r)
		{
			for (int c = 0; c < cols; ++c)
			{
				res += (grid[r][c] > 0) ? 2 : 0;
			}
		}

		//����
		for (int r = 0; r < rows; ++r)
		{
			res += grid[r][0];
			for (int c = 1; c < cols; ++c)
			{
				res += abs(grid[r][c] - grid[r][c - 1]);
			}
			res += grid[r][cols - 1];
		}

		//ǰ��
		for (int c = 0; c < cols; ++c)
		{
			res += grid[0][c];
			for (int r = 1; r < rows; ++r)
			{
				res += abs(grid[r][c] - grid[r - 1][c]);
			}
			res += grid[rows - 1][c];
		}
		return res;
	}
};
