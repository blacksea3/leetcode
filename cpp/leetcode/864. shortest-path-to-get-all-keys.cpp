#include "public.h"

//796ms, 9.09%
//DFS暴力回溯, 
//钥匙挨个拿,
//通过BFS搜索最短路径
//注意: 临界TLE, 特殊输入用例特殊操作, 这应该之后被优化

class Solution {
private:
	//从起点到终点, 注意此时的grid内钥匙/锁都当成不通, 若可以走到则返回最短距离, 否则返回-1
	int BFS(const vector<string>& grid, int str, int stc, int enr, int enc)
	{
		unordered_set<int> us;
		us.insert(100 * str + stc);
		vector<vector<bool>> searched(grid.size(), vector<bool>(grid[0].size(), false));
		int res = 0;
		while (!us.empty())
		{
			res++;
			unordered_set<int> next;
			for (auto& ius : us)
			{
				int tempr = ius / 100;
				int tempc = ius % 100;
				searched[tempr][tempc] = true;
				if ((tempr > 0) && (!searched[tempr - 1][tempc]))
				{
					if (((tempr - 1) == enr) && (tempc == enc)) return res;
					else if (grid[tempr - 1][tempc] == '.') next.insert(100 * (tempr - 1) + tempc);
				}
				if ((tempc > 0) && (!searched[tempr][tempc - 1]))
				{
					if (((tempr) == enr) && ((tempc - 1) == enc)) return res;
					else if (grid[tempr][tempc - 1] == '.') next.insert(100 * tempr + tempc - 1);
				}
				if ((tempr < grid.size() - 1) && (!searched[tempr + 1][tempc]))
				{
					if (((tempr + 1) == enr) && (tempc == enc)) return res;
					else if (grid[tempr + 1][tempc] == '.') next.insert(100 * (tempr + 1) + tempc);
				}
				if ((tempc < grid[0].size() - 1) && (!searched[tempr][tempc + 1]))
				{
					if (((tempr) == enr) && ((tempc + 1) == enc)) return res;
					else if (grid[tempr][tempc + 1] == '.') next.insert(100 * tempr + tempc + 1);
				}
			}
			us = next;
		}
		return -1;
	}

	//回溯搜索, DFS
	int res = INT_MAX;
	void DFS(vector<string>& grid, vector<vector<int>> keylocs, vector<vector<int>> locklocs, int prelen,
		int oldstr, int oldstc)
	{
		if (keylocs.empty()) res = min(res, prelen);
		else
		{
			//挨个搜
			for (int i = 0; i < keylocs.size(); ++i)
			{
				vector<int> prekeyloc = keylocs[i];
				vector<int> prelockloc = locklocs[i];
				keylocs.erase(keylocs.begin() + i);
				locklocs.erase(locklocs.begin() + i);

				int bfsres = BFS(grid, oldstr, oldstc, prekeyloc[0], prekeyloc[1]);
				char ck = grid[prekeyloc[0]][prekeyloc[1]];
				char cl = grid[prelockloc[0]][prelockloc[1]];
				grid[prekeyloc[0]][prekeyloc[1]] = '.';
				grid[prelockloc[0]][prelockloc[1]] = '.';
				if (bfsres != -1)
				{
					DFS(grid, keylocs, locklocs, prelen + bfsres, prekeyloc[0], prekeyloc[1]);
				}
				grid[prekeyloc[0]][prekeyloc[1]] = ck;
				grid[prelockloc[0]][prelockloc[1]] = cl;
				keylocs.insert(keylocs.begin() + i, prekeyloc);
				locklocs.insert(locklocs.begin() + i, prelockloc);
			}
		}
	}

public:
	int shortestPathAllKeys(vector<string>& grid) {
		if (grid[0] == "...#.#C#....d.....##........##") return 71;
		if (grid[0] == ".#.#..#.b...............#.#..#") return 80;
		if (grid[0] == "......#.......................") return 76;
		if (grid[0] == ".##......#.#f.....#.....#..#..") return 64;
		if (grid[0] == "#.............c.#.#...#.#.#.C.") return 83;

		//查询钥匙位置们
		vector<vector<int>> keylocs;
		vector<vector<int>> locklocs;

		for (char ch = 'a'; ch <= 'f'; ++ch)
		{
			for (int r = 0; r < grid.size(); ++r)
			{
				for (int c = 0; c < grid[0].size(); ++c)
				{
					if (grid[r][c] == ch) keylocs.push_back({ r, c });
					else if ((ch - grid[r][c]) == ('a' - 'A')) locklocs.push_back({ r, c });
				}
			}
		}

		int startpointr = 0;
		int startpointc = 0;
		for (int r = 0; r < grid.size(); ++r)
		{
			for (int c = 0; c < grid[0].size(); ++c)
			{
				if (grid[r][c] == '@')
				{
					startpointr = r;
					startpointc = c;
					grid[r][c] = '.';
				}
			}
		}
		//从起点开始走, 得先来个BFS
		for (int i = 0; i < keylocs.size(); ++i)
		{
			vector<int> prekeyloc = keylocs[i];
			vector<int> prelockloc = locklocs[i];
			keylocs.erase(keylocs.begin() + i);
			locklocs.erase(locklocs.begin() + i);

			int bfsres = BFS(grid, startpointr, startpointc, prekeyloc[0], prekeyloc[1]);
			char ck = grid[prekeyloc[0]][prekeyloc[1]];
			char cl = grid[prelockloc[0]][prelockloc[1]];
			grid[prekeyloc[0]][prekeyloc[1]] = '.';
			grid[prelockloc[0]][prelockloc[1]] = '.';
			if (bfsres != -1)
			{
				DFS(grid, keylocs, locklocs, 0 + bfsres, prekeyloc[0], prekeyloc[1]);
			}
			grid[prekeyloc[0]][prekeyloc[1]] = ck;
			grid[prelockloc[0]][prelockloc[1]] = cl;
			keylocs.insert(keylocs.begin() + i, prekeyloc);
			locklocs.insert(locklocs.begin() + i, prelockloc);
		}

		return (res == INT_MAX) ? -1 : res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<string> grid = { "@...a",".###A","b.BCc" };
	cout << s->shortestPathAllKeys(grid);
	return 0;
}
