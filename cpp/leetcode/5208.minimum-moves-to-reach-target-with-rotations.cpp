#include "public.h"

//
//BFS
//对于n*n的迷宫, 有(n-1)*n种横着的
//有n*(n-1)种竖着的位置

class Solution {
public:
	int minimumMoves(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<vector<bool>> seH(n - 1, vector<bool>(n, false));  //横的, 取尾巴所在位置
		vector<vector<bool>> seV(n, vector<bool>(n - 1, false));  //竖的, 取尾巴所在位置

		unordered_set<int> q;    //编码: 类型横0, 竖1, 乘1000000; r行乘1000, c列乘1
		unordered_set<int> his;

		q.insert(0);
		int res = 0;

		while (!q.empty())
		{
			unordered_set<int> ne;

			while (!q.empty())
			{
				int pre = *q.begin();
				q.erase(q.begin());
				int type = pre / 1000000;
				int r = (pre % 1000000)/ 1000;
				int c = pre % 1000;
				his.insert(pre);

				if (type == 0) //横的
				{
					if (r == (n - 1) && c == (n - 2)) goto BIGBREAK;
					int nextr, nextc;

					if (r < n - 1)
					{
						nextr = r + 1;
						nextc = c;
						int tempnext = (nextr) * 1000 + nextc;
						if (ne.find(tempnext) == ne.end() && (grid[nextr][nextc] == 0) &&
							(grid[nextr][nextc + 1] == 0) && q.find(tempnext) == q.end() &&
							his.find(tempnext) == his.end())
						{
							ne.insert(tempnext);
						}
					}
					if (c < n - 2)
					{
						nextr = r;
						nextc = c + 1;
						int tempnext = (nextr) * 1000 + nextc;
						if (ne.find(tempnext) == ne.end() && (grid[nextr][nextc] == 0) &&
							(grid[nextr][nextc + 1] == 0) && q.find(tempnext) == q.end() &&
							his.find(tempnext) == his.end())
						{
							ne.insert(tempnext);
						}
					}
					if (r < n - 1) //旋转
					{
						int tempnext = 1000000 + (r) * 1000 + c;
						if (ne.find(tempnext) == ne.end() && (grid[r + 1][c + 1] == 0) &&
							(grid[r + 1][c] == 0) && q.find(tempnext) == q.end() &&
							his.find(tempnext) == his.end())
						{
							ne.insert(tempnext);
						}
					}
				}
				else //竖的
				{
					int nextr, nextc;
					if (r < n - 2)
					{
						nextr = r + 1;
						nextc = c;
						int tempnext = 1000000 + (nextr) * 1000 + nextc;
						if (ne.find(tempnext) == ne.end() && (grid[nextr][nextc] == 0) &&
							(grid[nextr + 1][nextc] == 0) && q.find(tempnext) == q.end() &&
							his.find(tempnext) == his.end())
						{
							ne.insert(tempnext);
						}
					}
					if (c < n - 1)
					{
						nextr = r;
						nextc = c + 1;
						int tempnext = 1000000 + (nextr) * 1000 + nextc;
						if (ne.find(tempnext) == ne.end() && (grid[nextr][nextc] == 0) &&
							(grid[nextr + 1][nextc] == 0) && q.find(tempnext) == q.end() &&
							his.find(tempnext) == his.end())
						{
							ne.insert(tempnext);
						}
					}
					if (c < n - 1) //旋转
					{
						int tempnext = (r) * 1000 + c;
						if (ne.find(tempnext) == ne.end() && (grid[r + 1][c + 1] == 0) &&
							(grid[r][c + 1] == 0) && q.find(tempnext) == q.end() &&
							his.find(tempnext) == his.end())
						{
							ne.insert(tempnext);
						}
					}
				}
			}
			res++;
			q = ne;
		}
		return -1;
	BIGBREAK:
		return res;
	}
};

/*
int main()
{
	Solution*s = new Solution();
	vector<vector<int>> grid1 = { {0,0,0,0,0,1},
			   {1,1,0,0,1,0},
			   {0,0,0,0,1,1},
			   {0,0,1,0,1,0},
			   {0,1,1,0,0,0},
			   {0,1,1,0,0,0} };
	cout << s->minimumMoves(grid1);  //11

	vector<vector<int>> grid = { {0,0,0,0,0,0,0,0,0,1},{0,1,0,0,0,0,0,1,0,1},{1,0,0,1,0,0,1,0,1,0},{0,0,0,1,0,1,0,1,0,0},{0,0,0,0,1,0,0,0,0,1},{0,0,1,0,0,0,0,0,0,0},{1,0,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0} };
	cout << s->minimumMoves(grid);
	return 0;
}
*/
