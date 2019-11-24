#include "public.h"

//
//����, �з���������==1���б���һ��

class Solution {
public:
	int countServers(vector<vector<int>>& grid) {
		int res = 0;
		for (int i = 0; i < grid.size(); ++i)
		{
			int preCols = 0;
			int firstCol = -1;
			for (int j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j] == 1)
				{
					preCols++;
					if (firstCol == -1)
					{
						firstCol = j;
					}
				}
			}
			if (preCols == 0 || preCols > 1)
			{
				res += preCols;
			}
			else
			{
				//�Ե�ǰ����һ��, ����
				int preRows = 0;
				for (int row = 0; row < grid.size(); ++row)
				{
					if (grid[row][firstCol] == 1)
					{
						preRows++;
					}
				}
				if (preRows > 1)
				{
					res++;
				}
			}
		}
		return res;
	}
};
