#include "public.h"

//16ms, 33.33%
//此题仅需BFS模拟

class Solution {
private:
	int num_fresh = 0;
	vector<vector<int>> BFS(vector<vector<int>>& grid, vector<vector<int>> pre)
	{
		vector<vector<int>> next;
		for (int i = 0; i < pre.size(); ++i)
		{
			int r = pre[i][0];
			int c = pre[i][1];
			if (r > 0 && grid[r - 1][c] == 1)
			{
				next.push_back({ r - 1, c });
				grid[r - 1][c] = 2;
				num_fresh--;
			}
			if (c > 0 && grid[r][c - 1] == 1)
			{
				next.push_back({ r, c - 1 });
				grid[r][c - 1] = 2;
				num_fresh--;
			}
			if (r < grid.size() - 1 && grid[r + 1][c] == 1)
			{
				next.push_back({ r + 1, c });
				grid[r + 1][c] = 2;
				num_fresh--;
			}
			if (c < grid[0].size() - 1 && grid[r][c + 1] == 1)
			{
				next.push_back({ r, c + 1 });
				grid[r][c + 1] = 2;
				num_fresh--;
			}
		}
		return next;
	}

public:
	int orangesRotting(vector<vector<int>>& grid) {
		vector<vector<int>> start;
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j] == 2) start.push_back({ i, j });
				else if (grid[i][j] == 1) num_fresh++;
			}
		}

		int res = 0;

		//main BFS
		while (true)
		{
			if (num_fresh == 0) return res;
			else if (start.empty()) return -1;
			else
			{
				start = BFS(grid, start);
				res++;
			}
		}
		return -999; //dump
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> r = { {2,1,1},{1,1,0},{0,1,1} };
	auto res = s->orangesRotting(r);
	return 0;
}
*/