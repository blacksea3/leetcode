#include "public.h"

//52ms, 17.31%
//转换: N*N->3N*3N; /->001   \->  100  ' '-> 000
//                     010        010        000
//                     100        001        000
//然后求多少个分离的0块

class Solution {
private:
	void DFS(vector<vector<bool>>& v, int r, int c)
	{
		v[r][c] = true;
		if (r > 0 && !v[r - 1][c]) DFS(v, r - 1, c);
		if (c > 0 && !v[r][c - 1]) DFS(v, r, c - 1);
		if (r < v.size() - 1 && !v[r + 1][c]) DFS(v, r + 1, c);
		if (c < v.size() - 1 && !v[r][c + 1]) DFS(v, r, c + 1);
	}

public:
	int regionsBySlashes(vector<string>& grid) {
		//convert
		size_t ns = 3 * grid.size();
		vector<vector<bool>> v(ns, vector<bool>(ns, false));

		for (int r = 0; r < grid.size(); ++r)
		{
			int realc = 0;
			int imagc = 0;
			while (imagc < grid.size())
			{
				if (grid[r][realc] == ' ')
				{
					realc++;
				}
				else if (grid[r][realc] == '/')
				{
					v[3 * r][3 * imagc + 2] = true;
					v[3 * r + 1][3 * imagc + 1] = true;
					v[3 * r + 2][3 * imagc] = true;
					realc++;
				}
				else
				{
					v[3 * r + 2][3 * imagc + 2] = true;
					v[3 * r + 1][3 * imagc + 1] = true;
					v[3 * r][3 * imagc] = true;
					realc++;
				}
				imagc++;
			}
		}

		//DFS
		int res = 0;
		for (int r = 0; r < v.size(); ++r)
		{
			for (int c = 0; c < v.size(); ++c)
			{
				if (!v[r][c])
				{
					res++;
					DFS(v, r, c);
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	//vector<string> grid = { " /", "/ " };
	//cout << s->regionsBySlashes(grid);
	vector<string> grid = { "   /\\ \\\\\\\\","\\  \\///\\/ ","\\/\\\\\\// \\\\","\\ /// /\\ \\"," / //// //","// ///\\ \\/"," \\ \\\\// \\/","// \\\\\\\\\\\\\\","\\ //\\////\\","\\/\\\\/\\\\\\\\\\" };
	cout << s->regionsBySlashes(grid);
	return 0;
}
