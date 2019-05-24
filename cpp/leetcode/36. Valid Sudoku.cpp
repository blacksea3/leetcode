#include "public.h"

//20ms, 95.86%

//this is an easy question, just write down some if/else sentenses

//note the 3 * (i / 3) + j / 3 == its(the location's) group: group is from 0 to 8

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		//one traverse
		vector<vector<char>> rows(9);
		vector<vector<char>> columns(9);
		vector<vector<char>> groups(9);
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.') continue;
				if (find(rows[i].begin(), rows[i].end(), board[i][j]) == rows[i].end())
					rows[i].push_back(board[i][j]);
				else
					return false;
				if (find(columns[j].begin(), columns[j].end(), board[i][j]) == columns[j].end())
					columns[j].push_back(board[i][j]);
				else
					return false;
				if (find(groups[3 * (i / 3) + j / 3].begin(), groups[3 * (i / 3) + j / 3].end(), board[i][j]) == groups[3 * (i / 3) + j / 3].end())
					groups[3 * (i / 3) + j / 3].push_back(board[i][j]);
				else
					return false;
			}
		}
		return true;
	}
};