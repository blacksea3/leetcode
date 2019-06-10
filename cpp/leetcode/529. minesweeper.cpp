#include "public.h"

//96ms, 58.02%, the find_num_neighbour_bombs shall be optimized :(
//DFS problem,
// there are no special tricks..

class Solution {
private:
	//if return the num of neighbour_bombs, note board[line][column] shall not be bomb
	int find_num_neighbour_bombs(vector<vector<char>>& board, const int& line, const int& column)
	{
		//if (board[line][column] == 'M') return -1;
		int res = 0;
		if (line > 0)
		{
			if (column > 0) if (board[line - 1][column-1] == 'M') res++;
			if (column < board[0].size()-1) if (board[line - 1][column + 1] == 'M') res++;
			if (board[line-1][column] == 'M') res++;
		}
		if (line < board.size() - 1)
		{
			if (column > 0) if (board[line + 1][column - 1] == 'M') res++;
			if (column < board[0].size() - 1) if (board[line + 1][column + 1] == 'M') res++;
			if (board[line + 1][column] == 'M') res++;
		}
		if (column > 0) if (board[line][column - 1] == 'M') res++;
		if (column < board[0].size() - 1) if (board[line][column + 1] == 'M') res++;
		return res;
	}

	void recu_update_board(vector<vector<char>>& board, const int& line, const int& column)
	{
		int tempres = find_num_neighbour_bombs(board, line, column);
		if (tempres == 0)
		{
			board[line][column] = 'B';
			if (line > 0)
			{
				if (column > 0) if (board[line - 1][column - 1] == 'E') recu_update_board(board, line - 1, column - 1);
				if (column < board[0].size() - 1) if (board[line - 1][column + 1] == 'E') recu_update_board(board, line - 1, column + 1);
				if (board[line - 1][column] == 'E') recu_update_board(board, line - 1, column);
			}
			if (line < board.size() - 1)
			{
				if (column > 0) if (board[line + 1][column - 1] == 'E') recu_update_board(board, line + 1, column - 1);
				if (column < board[0].size() - 1) if (board[line + 1][column + 1] == 'E') recu_update_board(board, line + 1, column + 1);
				if (board[line + 1][column] == 'E') recu_update_board(board, line + 1, column);
			}
			if (column > 0) if (board[line][column - 1] == 'E') recu_update_board(board, line, column - 1);
			if (column < board[0].size() - 1) if (board[line][column + 1] == 'E') recu_update_board(board, line, column + 1);
		}
		else
		{
			board[line][column] = tempres + '0';
		}
	}

public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		int line = click[0];
		int column = click[1];
		
		if (board[line][column] == 'M')   //only the top call can enter it!
		{
			board[line][column] = 'X';
			return board;
		}
		else
		{
			int tempres = find_num_neighbour_bombs(board, line, column);
			if (tempres == 0)
			{
				board[line][column] = 'B';
				if (line > 0)
				{
					if (column > 0) if (board[line - 1][column - 1] == 'E') recu_update_board(board, line - 1, column - 1);
					if (column < board[0].size() - 1) if (board[line - 1][column + 1] == 'E') recu_update_board(board, line - 1, column + 1);
					if (board[line - 1][column] == 'E') recu_update_board(board, line - 1, column);
				}
				if (line < board.size() - 1)
				{
					if (column > 0) if (board[line + 1][column - 1] == 'E') recu_update_board(board, line + 1, column - 1);
					if (column < board[0].size() - 1) if (board[line + 1][column + 1] == 'E') recu_update_board(board, line + 1, column + 1);
					if (board[line + 1][column] == 'E') recu_update_board(board, line + 1, column);
				}
				if (column > 0) if (board[line][column - 1] == 'E') recu_update_board(board, line, column - 1);
				if (column < board[0].size() - 1) if (board[line][column + 1] == 'E') recu_update_board(board, line, column + 1);
			}
			else
			{
				board[line][column] = tempres + '0';
			}
		}
		return board;
	}
};
