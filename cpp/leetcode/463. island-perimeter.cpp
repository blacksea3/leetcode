#include "public.h"

//208ms, 5.36%
//DFS
//ע��ֻ��һ���������û�к�
//�������ĳ�������Ǳ߽����ˮ, ��ô�������㵽�ܳ�����

class Solution {
private:
	int res = 0;
	void DFS(const vector<vector<int>>& grid, vector<vector<bool>>& issearched,
		int r, int c)
	{
		issearched[r][c] = true;
		if (r == 0) res++;
		else
		{
			if (grid[r - 1][c] == 0) res++;
			else if (!issearched[r - 1][c]) DFS(grid, issearched, r - 1, c);
		}

		if (c == 0) res++;
		else
		{
			if (grid[r][c - 1] == 0) res++;
			else if (!issearched[r][c - 1]) DFS(grid, issearched, r, c - 1);
		}

		if (r == grid.size() - 1) res++;
		else
		{
			if (grid[r + 1][c] == 0) res++;
			else if (!issearched[r + 1][c]) DFS(grid, issearched, r + 1, c);
		}

		if (c == grid[0].size() - 1) res++;
		else
		{
			if (grid[r][c + 1] == 0) res++;
			else if (!issearched[r][c + 1]) DFS(grid, issearched, r, c + 1);
		}
	}

public:
	int islandPerimeter(vector<vector<int>>& grid) {
		vector<vector<bool>> issearched(grid.size(), vector<bool>(grid[0].size(), false));
		//�ҵ�һ��½��, DFS
		for (int r = 0; r < grid.size(); ++r)
			for (int c = 0; c < grid[0].size(); ++c)
				if (grid[r][c] == 1)
				{
					DFS(grid, issearched, r, c);
					goto bigbreak;
				}
	bigbreak:
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
