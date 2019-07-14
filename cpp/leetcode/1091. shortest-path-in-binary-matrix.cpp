#include "public.h"

//244ms, 9.95%
//典型的BFS问题

class Solution {
private:
	int res = 0;
	void BFS(vector<vector<int>>& grid, vector<vector<bool>>& searched, vector<pair<int, int>> pre, int length)
	{
		int N = grid.size();
		pair<int, int> p;
		p.first = N - 1;
		p.second = N - 1;
		if (find(pre.begin(), pre.end(), p) != pre.end())
		{
			res = length + 1;
			return;
		}
		else if (pre.size() == 0)
		{
			res = -1;
			return;
		}
		else
		{
			vector<pair<int, int>> next;
			for (auto p : pre)
			{
				int row = p.first;
				int col = p.second;
				vector<pair<int, int>> nextabs = { {1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,0},{-1,1},{-1,-1} };

				for (int i = 0; i < 8; ++i)
				{
					int nextrow = row + nextabs[i].first;
					int nextcol = col + nextabs[i].second;
					if ((nextrow >= 0) && (nextrow < N) && (nextcol >= 0) && (nextcol < N) && (!searched[nextrow][nextcol]) && (grid[nextrow][nextcol] == 0))
					{
						next.push_back({ nextrow,nextcol });
						searched[nextrow][nextcol] = true;
					}
				}
			}
			length += 1;
			BFS(grid, searched, next, length);
		}
	}

public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		//BFS
		vector<vector<bool>> searched(grid.size(), vector<bool>(grid[0].size(), false));
		if (grid[0][0] == 1) return -1;

		BFS(grid, searched, { {0,0} }, 0);
		return res;
	}
};
