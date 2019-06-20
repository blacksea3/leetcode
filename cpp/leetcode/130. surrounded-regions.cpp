#include "public.h"

//44ms, 86.57%

//DFS
//先对边界搜一轮O,变成A   
//然后对中间遍历O变成X
//然后边界遍历把A变成O

class Solution {
private:
	void DFS_O2A(vector<vector<char>>& board, int line, int column, int& maxline, int& maxcolumn)
	{
		if ((line < 0) || (line == maxline) || (column < 0) || (column == maxcolumn)) return;
		if (board[line][column] == 'O')
		{
			board[line][column] = 'A';
			DFS_O2A(board, line - 1, column, maxline, maxcolumn);
			DFS_O2A(board, line, column - 1, maxline, maxcolumn);
			DFS_O2A(board, line + 1, column, maxline, maxcolumn);
			DFS_O2A(board, line, column + 1, maxline, maxcolumn);
		}
	}
public:
	void solve(vector<vector<char>>& board) {
		int maxline = board.size();
		if (maxline == 0) return;
		int maxcolumn = board[0].size();
		if (maxcolumn == 0) return;

		//first DFS, border O -> A
		for (int col = 0; col < maxcolumn; ++col)
			DFS_O2A(board, 0, col, maxline, maxcolumn);
		for (int col = 0; col < maxcolumn; ++col)
			DFS_O2A(board, maxline - 1, col, maxline, maxcolumn);
		for (int lin = 1; lin < maxline - 1; ++lin)
			DFS_O2A(board, lin, 0, maxline, maxcolumn);
		for (int lin = 1; lin < maxline - 1; ++lin)
			DFS_O2A(board, lin, maxcolumn - 1, maxline, maxcolumn);

		//second traverse, inner O -> X
		for (int lin = 1; lin < maxline - 1; ++lin)
			for (int col = 1; col < maxcolumn - 1; ++col)
				if (board[lin][col] == 'O') board[lin][col] = 'X';

		//third: traverse, A -> O
		for (int lin = 0; lin < maxline; ++lin)
			for (int col = 0; col < maxcolumn; ++col)
			if (board[lin][col] == 'A') board[lin][col] = 'O';
				
	}
};

int main()
{
	Solution* s = new Solution();
	vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, { 'X', 'O', 'O', 'X' }, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
	s->solve(board);

	return 0;
}
