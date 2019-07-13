#include "public.h"

//12ms, 77.08%
//当搜索到X时只需要判断上面和左边是否同时不是X, 是的话则记为新的战舰(的左上角部分), 否则它是其他部分

class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {
		if (board.size() == 0) return 0;
		int res = 0;

		//cols = 0无需单独判断
		for (int row = 0; row < board.size(); ++row)
		{
			for (int col = 0; col < board[0].size(); ++col)
			{
				if ((board[row][col] == 'X') && ((row == 0) || ((row > 0) && (board[row - 1][col] == '.'))) && ((col == 0) || ((col > 0) && (board[row][col - 1] == '.')))) res++;
			}
		}
		return res;
	}
};


