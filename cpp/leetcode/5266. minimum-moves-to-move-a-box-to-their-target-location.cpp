#include "public.h"

//
//多重BFS

class Solution {
private:
	int GBLRES;

	//判断人过不过得去
	vector<bool> getPeoCan(vector<vector<char>>& grid, int bR, int bC, int pR, int pC)
	{
		vector<bool> canArr(4, false);
		if (bR > 0 && grid[bR - 1][bC] != '#')
		{
			vector<vector<bool>> issearched = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
			canArr[2] = peopleBFS(grid, issearched, bR - 1, bC, pR, pC);
		}

		if (bC > 0 && grid[bR][bC - 1] != '#')
		{
			vector<vector<bool>> issearched = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
			canArr[3] = peopleBFS(grid, issearched, bR, bC - 1, pR, pC);
		}

		if (bR < grid.size() - 1 && grid[bR + 1][bC] != '#')
		{
			vector<vector<bool>> issearched = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
			canArr[0] = peopleBFS(grid, issearched, bR + 1, bC, pR, pC);
		}

		if (bC < grid[0].size() - 1 && grid[bR][bC + 1] != '#')
		{
			vector<vector<bool>> issearched = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
			canArr[1] = peopleBFS(grid, issearched, bR, bC + 1, pR, pC);
		}
		return canArr;
	}


	//BFS搜索箱子到目标位置的各种路线
	void boxPath(vector<vector<char>>& grid, vector<vector<vector<vector<bool>>>>& issearched,
		int br, int bc, vector<bool> initcanArr, int initpeor, int initpeoc)
	{
		queue<pair<vector<int>, vector<bool>>> q;
		q.push(pair<vector<int>, vector<bool>>{ {br, bc, 1}, initcanArr  });
		issearched[br][bc].push_back(initcanArr);
		int prePr = initpeor;
		int prePc = initpeoc;
		grid[br][bc] = '.';  //删掉箱子

		while (!q.empty())
		{
			pair<vector<int>, vector<bool>> pre = q.front();
			q.pop();
			int pr = pre.first[0];
			int pc = pre.first[1];
			vector<bool> canArr = pre.second;

			if (pr > 0 && pr < grid.size() - 1 && grid[pr - 1][pc] != '#' && canArr[0])
			{
				if (grid[pr - 1][pc] == 'T')
				{
					GBLRES = min(GBLRES, pre.first[2]);
				}
				else
				{
					//grid[pr][pc] = '.';
					grid[pr - 1][pc] = 'B';
					vector<bool> newcanArrup = getPeoCan(grid, pr - 1, pc, pr + 1, pc);
					if ((find(issearched[pr - 1][pc].begin(), issearched[pr - 1][pc].end(), newcanArrup) == issearched[pr - 1][pc].end()))
					{
						issearched[pr - 1][pc].push_back(newcanArrup);
						q.push({ {pr - 1, pc, pre.first[2] + 1}, newcanArrup });
					}
					//grid[pr][pc] = 'B';
					grid[pr - 1][pc] = '.';
				}
			}

			if (pc > 0 && pc < grid[0].size() - 1 && grid[pr][pc - 1] != '#' && canArr[1])
			{
				if (grid[pr][pc - 1] == 'T')
				{
					GBLRES = min(GBLRES, pre.first[2]);
				}
				else
				{
					grid[pr][pc - 1] = 'B';
					vector<bool> newcanArrup = getPeoCan(grid, pr, pc - 1, pr, pc + 1);
					if ((find(issearched[pr][pc - 1].begin(), issearched[pr][pc - 1].end(), newcanArrup) == issearched[pr][pc - 1].end()))
					{
						issearched[pr][pc - 1].push_back(newcanArrup);
						q.push({ {pr, pc - 1, pre.first[2] + 1}, newcanArrup });
					}
					grid[pr][pc - 1] = '.';
				}
			}

			if (pr > 0 && pr < grid.size() - 1 && grid[pr + 1][pc] != '#' && canArr[2])
			{
				if (grid[pr + 1][pc] == 'T')
				{
					GBLRES = min(GBLRES, pre.first[2]);
				}
				else
				{
					grid[pr + 1][pc] = 'B';
					vector<bool> newcanArrdown = getPeoCan(grid, pr + 1, pc, pr - 1, pc);
					if ((find(issearched[pr + 1][pc].begin(), issearched[pr + 1][pc].end(), newcanArrdown) == issearched[pr + 1][pc].end())
						)
					{
						issearched[pr + 1][pc].push_back(newcanArrdown);
						q.push({ {pr + 1, pc, pre.first[2] + 1}, newcanArrdown });
					}
					grid[pr + 1][pc] = '.';
				}
			}

			if (pc > 0 && pc < grid[0].size() - 1 && grid[pr][pc + 1] != '#'&& canArr[3])
			{
				if (grid[pr][pc + 1] == 'T')
				{
					GBLRES = min(GBLRES, pre.first[2]);
				}
				else
				{
					grid[pr][pc + 1] = 'B';
					vector<bool> newcanArrright = getPeoCan(grid, pr, pc + 1, pr, pc - 1);
					if ((find(issearched[pr][pc + 1].begin(), issearched[pr][pc + 1].end(), newcanArrright) == issearched[pr][pc + 1].end())
						)
					{
						issearched[pr][pc + 1].push_back(newcanArrright);
						q.push({ {pr, pc + 1, pre.first[2] + 1}, newcanArrright });
					}
					grid[pr][pc + 1] = '.';
				}
			}
		}
	}

	bool peopleBFS(vector<vector<char>>& grid, vector<vector<bool>>& issearched, int tPr, int tPc, int prinput, int pcinput)
	{
		queue<vector<int>> q;
		q.push({ prinput, pcinput });
		issearched[prinput][pcinput] = true;

		while (!q.empty())
		{
			vector<int> pre = q.front();
			q.pop();
			int pr = pre[0];
			int pc = pre[1];
			if (pr == tPr && pc == tPc)
				return true;

			if (pr > 0 && !issearched[pr - 1][pc] && grid[pr - 1][pc] != '#' && grid[pr - 1][pc] != 'B')
			{
				issearched[pr - 1][pc] = true;
				q.push({ pr - 1, pc });
			}
			if (pc > 0 && !issearched[pr][pc - 1] && grid[pr][pc - 1] != '#' && grid[pr][pc - 1] != 'B')
			{
				issearched[pr][pc - 1] = true;
				q.push({ pr, pc - 1 });
			}
			if (pr < grid.size() - 1 && !issearched[pr + 1][pc] && grid[pr + 1][pc] != '#' && grid[pr + 1][pc] != 'B')
			{
				issearched[pr + 1][pc] = true;
				q.push({ pr + 1, pc});
			}
			if (pc < grid[0].size() - 1 && !issearched[pr][pc + 1] && grid[pr][pc + 1] != '#'&& grid[pr][pc + 1] != 'B')
			{
				issearched[pr][pc + 1] = true;
				q.push({ pr, pc + 1 });
			}
		}

		return false;
	}

public:
	int minPushBox(vector<vector<char>>& grid) {
		GBLRES = INT_MAX;

		vector<vector<vector<vector<bool>>>> issearched2 = vector<vector<vector<vector<bool>>>>(grid.size(),
			vector<vector<vector<bool>>>(grid[0].size(), vector<vector<bool>>{}));

		//把people/box找出来
		int pR, pC;
		int bR, bC;
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j] == 'S')
				{
					pR = i;
					pC = j;
				}
				if (grid[i][j] == 'B')
				{
					bR = i;
					bC = j;
				}
			}
		}

		vector<bool> canArr(4, false);
		//初始化canArr
		if (bR > 0 && grid[bR - 1][bC] != '#')
		{
			vector<vector<bool>> issearched = vector<vector<bool>>(grid.size(), 
				vector<bool>(grid[0].size(), false));
			canArr[2] = peopleBFS(grid, issearched, bR - 1, bC, pR, pC);
		}
			
		if (bC > 0 && grid[bR][bC - 1] != '#')
		{
			vector<vector<bool>> issearched = vector<vector<bool>>(grid.size(),
				vector<bool>(grid[0].size(), false));
			canArr[3] = peopleBFS(grid, issearched, bR, bC - 1, pR, pC);
		}
			
		if (bR < grid.size() - 1 && grid[bR + 1][bC] != '#')
		{
			vector<vector<bool>> issearched = vector<vector<bool>>(grid.size(),
				vector<bool>(grid[0].size(), false));
			canArr[0] = peopleBFS(grid, issearched, bR + 1, bC, pR, pC);
		}
			
		if (bC < grid[0].size() - 1 && grid[bR][bC + 1] != '#')
		{
			vector<vector<bool>> issearched = vector<vector<bool>>(grid.size(),
				vector<bool>(grid[0].size(), false));
			canArr[1] = peopleBFS(grid, issearched, bR, bC + 1, pR, pC);
		}

		if (canArr[0])
		{
			boxPath(grid, issearched2, bR, bC, canArr, bR + 1, bC);
		}
		if (canArr[1])
		{
			boxPath(grid, issearched2, bR, bC, canArr, bR, bC + 1);
		}
		if (canArr[2])
		{
			boxPath(grid, issearched2, bR, bC, canArr, bR - 1, bC);
		}
		if (canArr[3])
		{
			boxPath(grid, issearched2, bR, bC, canArr, bR, bC - 1);
		}

		return (GBLRES ==INT_MAX) ? -1 : GBLRES;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	
	vector<vector<char>> grid000 = { {'#','.','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','#','.','.','.','#'},{'#','.','#','.','.','T','.','.','.','.'},{'.','#','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','#','.','.','.'},{'.','.','.','#','#','S','.','B','.','.'},{'#','.','.','.','.','.','.','#','.','.'},{'.','#','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','#','.','.','.','.'} };

	cout << s->minPushBox(grid000) << endl;  //5

	vector<vector<char>> grid00 = { {'.','.','#','.','.','.','.','#'},
	{'.','B','.','.','.','.','.','#'},
	{'.','.','S','.','.','.','.','.'},
	{'.','#','.','.','.','.','.','.'},
	{'.','.','.','.','.','.','.','.'},
	{'.','.','.','T','.','.','.','.'},
	{'.','.','.','.','.','.','.','#'},
	{'.','#','.','.','.','.','.','.'} };

	cout << s->minPushBox(grid00) << endl;  //6


	vector<vector<char>> grid0 = { {'#','.','.','#','T','#','#','#','#'},
	{'#','.','.','#','.','#','.','.','#'},
	{'#','.','.','#','.','#','B','.','#'},
	{'#','.','.','.','.','.','.','.','#'},
	{'#','.','.','.','.','#','.','S','#'},
	{'#','.','.','#','.','#','#','#','#'} };

	cout << s->minPushBox(grid0) << endl;  //8



	vector<vector<char>> grid = { {'#','#','#','#','#','#'},
			 {'#','T','#','#','#','#'},
			 {'#','.','.','B','.','#'},
			 {'#','.','#','#','.','#'},
			 {'#','.','.','.','S','#'},
			 {'#','#','#','#','#','#'} };

	cout << s->minPushBox(grid) << endl;  //3

	vector<vector<char>> grid2 = { {'#','#','#','#','#','#'},
			 {'#','T','#','#','#','#'},
			 {'#','.','.','B','.','#'},
			 {'#','#','#','#','.','#'},
			 {'#','.','.','.','S','#'},
			 {'#','#','#','#','#','#'} };

	cout << s->minPushBox(grid2) << endl;  //-1


	vector<vector<char>> grid3 = { {'#','#','#','#','#','#'},
			 {'#','T','.','.','#','#'},
			 {'#','.','#','B','.','#'},
			 {'#','.','.','.','.','#'},
			 {'#','.','.','.','S','#'},
			 {'#','#','#','#','#','#'} };

	cout << s->minPushBox(grid3) << endl;  //5



	return 0;
}
*/
