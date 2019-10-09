#include "public.h"

//68ms, 97.55%
//ע��ֻ��һ���������û�к�
//���ڵ���: ÿ����Χ��һ���������ܳ����׼�1, ÿ����������ܳ�������4
//ֱ��˫��ѭ��

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int res = 0;
		int gSize = grid.size();
		int g0Size = grid[0].size();
		for (int r = 0; r < gSize; ++r)
			for (int c = 0; c < g0Size; ++c)
			{
				if (grid[r][c] == 1)
				{
					int contribute = 4;
					if (r > 0 && grid[r - 1][c] == 1) contribute--;
					if (c > 0 && grid[r][c - 1] == 1) contribute--;
					if (r < (gSize - 1)&& grid[r + 1][c] == 1) contribute--;
					if (c < (g0Size - 1) && grid[r][c + 1] == 1) contribute--;
					res += contribute;
				}
			}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> grid = { {0,1,0,0},{0,1,0,0},{0,0,0,0},{0,0,0,0} };
	cout << s->islandPerimeter(grid);
	return 0;
}
*/
