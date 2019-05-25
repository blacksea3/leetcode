#include "public.h"

//20ms, 77.40%

//This is a typical DFS(BackTracking) problem: Here I use recursive solution
//use tricks: consider these structures: rows: 9 values, each is a 9 bool, columns: 9 values, each is a 9 bool;
// groups: 9 values, each is a 9 bool.

// for these 9 bool: the ?nd bool means whether ?+1 is used,  (1<=?+1<=9, ?+1 is the positive/real integer)

class Solution {
private:
	bool DFS(vector<vector<char>>& board, vector<vector<bool>>& rows, vector<vector<bool>>& columns, vector<vector<bool>>& groups, 
		const vector<pair<int, int>>& blanks, int pre_filled)
	{
		if (pre_filled < blanks.size())
		{
			int y = blanks[pre_filled].first;
			int x = blanks[pre_filled].second;
			int groupid = 3 * (y / 3) + x / 3;
			for (char i = 0; i < 9; i++)
			{
				if (rows[y][i] || columns[x][i] || groups[groupid][i]) continue;
				else
				{
					board[y][x] = i + '1';
					rows[y][i] = true;
					columns[x][i] = true;
					groups[groupid][i] = true;
				}
				if (DFS(board, rows, columns, groups, blanks, pre_filled + 1)) return true;
				else
				{
					board[y][x] = '.';
					rows[y][i] = false;
					columns[x][i] = false;
					groups[groupid][i] = false;
				}
			}
			return false;
		}
		return true;
	}

public:
	void solveSudoku(vector<vector<char>>& board) {
		//You may assume that the given Sudoku puzzle will have a single unique solution.
		//one traverse
		//consider that: if use recu: the max length < blanks.size(), so we can use it
		vector<vector<bool>> rows(9, vector<bool>(9, false));
		vector<vector<bool>> columns(9, vector<bool>(9, false));
		vector<vector<bool>> groups(9, vector<bool>(9, false));
		vector<pair<int, int>> blanks = {};
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.') blanks.push_back(pair<int, int>{i, j});
				else
				{
					char tempnum = board[i][j] - '1';
					rows[i][tempnum] = true;
					columns[j][tempnum] = true;
					groups[3 * (i / 3) + j / 3][tempnum] = true;
				}
			}
		}

		//theoretically, use the return value, one can judge if there has a solution
		DFS(board, rows, columns, groups, blanks, 0);
	}
};

int main()
{
	Solution* s = new Solution();
	vector<vector<char>> board = { {'5', '3', '5', '.', '7', '.', '.', '.', '.'},
	{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
	{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	{'.', '.', '.', '.', '.', '5', '.', '.', '.'},
	{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	{'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
	s->solveSudoku(board);
}

