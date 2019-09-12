#include "public.h"

//60ms, 98.42%
//原地算法, 模拟
//用矩阵的第一行和第一列存储需要调整至0的行和列

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0) return;
		int n = matrix[0].size();
		if (n == 0) return;

		bool isrow0_needset0 = false;
		bool iscolumn0_needset0 = false;
		for (int i = 0; i < m; i++)
		{
			if (matrix[i][0] == 0)
			{
				iscolumn0_needset0 = true;
				break;
			}
		}

		for (int j = 0; j < n; j++)
		{
			if (matrix[0][j] == 0)
			{
				isrow0_needset0 = true;
				break;
			}
		}

		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}

		for (int i = 1; i < m; i++)
		{
			if (matrix[i][0] == 0)
				for (int j = 1; j < n; j++)
					matrix[i][j] = 0;
		}

		for (int j = 1; j < n; j++)
		{
			if (matrix[0][j] == 0)
				for (int i = 1; i < m; i++)
					matrix[i][j] = 0;
		}

		if (isrow0_needset0)
			for (int j = 0; j < n; j++)
				matrix[0][j] = 0;

		if (iscolumn0_needset0)
			for (int i = 0; i < m; i++)
				matrix[i][0] = 0;
	}
};

