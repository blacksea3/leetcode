#include <iostream>
#include <vector>
#include <set>

using namespace std;

//DFS, 根据题目意思: 一定有解
bool isFindRes;
set<int> getPossibleVal(vector<vector<int>> const& board, int pr, int pc)
{
	set<int> v = { 1,2,3,4,5,6,7,8,9 };
	for (int r = 0; r < 9; ++r)
	{
		if (board[r][pc] != 0 && v.find(board[r][pc]) != v.end())
			v.erase(board[r][pc]);
	}
	for (int c = 0; c < 9; ++c)
	{
		if (board[pr][c] != 0 && v.find(board[pr][c]) != v.end())
			v.erase(board[pr][c]);
	}
	int baser = pr / 3 * 3;
	int basec = pc / 3 * 3;
	for (int ir = 0; ir < 3; ++ir)
	{
		for (int ic = 0; ic < 3; ++ic)
		{
			if (board[baser + ir][basec + ic] != 0 && v.find(board[baser + ir][basec + ic]) != v.end())
				v.erase(board[baser + ir][basec + ic]);
		}
	}
	return v;
}

void DFS(vector<vector<int>>& board, int startr, int startc)
{
	if (!isFindRes)
	{
		//寻找下一个目标位置
		while (true) //理论上一定在内部return 如果输入合法
		{
			if (startr == 8 && startc == 9)
			{
				isFindRes = true;
				return;
			}
			else
			{
				if (startc == 9)
				{
					startr++;
					startc = 0;
				}
				else if (board[startr][startc] == 0)
				{
					set<int> s = getPossibleVal(board, startr, startc);
					for (auto& iters : s)
					{
						board[startr][startc] = iters;
						DFS(board, startr, startc + 1);
						if (isFindRes) return;
						board[startr][startc] = 0;
					}
					return;
				}
				else startc++;
			}
		}
		return; //dump return
	}
	else return; //已经找到了解
}

int main()
{
	{
		/*
		vector<vector<int>> board(9, vector<int>(9, 0));
		for (int r = 0; r < 9; ++r)
		{
			for (int c = 0; c < 9; ++c)
			{
				cin >> board[r][c];
			}
		}
		*/
		/*vector<vector<int>> board =
		{ {5,3,0,0,7,0,0,0,0},
		  {6,0,0,1,9,5,0,0,0},
		  {0,9,8,0,0,0,0,6,0},
		  {8,0,0,0,6,0,0,0,3},
		  {4,0,0,8,0,3,0,0,1},
		  {7,0,0,0,2,0,0,0,6},
		  {0,6,0,0,0,0,2,8,0},
		  {0,0,0,4,1,9,0,0,5},
		  {0,0,0,0,8,0,0,7,9} };*/
		vector<vector<int>> board =
		{
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0}
		};

		DFS(board, 0, 0);
		//输出
		for (int r = 0; r < 9; ++r)
		{
			for (int c = 0; c < 9; ++c)
			{
				cout << board[r][c] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
