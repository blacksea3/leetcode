#include "public.h"

//4ms, 92.57%
//注意到这里一个元素是int
//自由扩展int值, 以强行储存当前值和更新值
//定义: 1:未遍历到的当前活细胞/遍历后仍然存活的活细胞
//      2:遍历后即将死亡的活细胞
//      0:未遍历到的当前死细胞/遍历后仍然死亡的细胞
//      -1:遍历后即将复活的死细胞

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int row = board.size();
		if (!row) return;
		int col = board[0].size();
		if (!col) return;

		//第一轮遍历: 更改状态
		for (int r = 0; r < row; ++r)
		{
			for (int c = 0; c < col; ++c)
			{
				int temp = 0;
				if (r > 0)
				{
					if ((c > 0) && (board[r - 1][c - 1] > 0)) temp++;
					if (board[r - 1][c] > 0) temp++;
					if ((c < col - 1) && (board[r - 1][c + 1] > 0)) temp++;
				}
				if ((c > 0) && (board[r][c - 1] > 0)) temp++;
				if ((c < col - 1) && (board[r][c + 1] > 0)) temp++;
				if (r < row - 1)
				{
					if ((c > 0) && (board[r + 1][c - 1] > 0)) temp++;
					if (board[r + 1][c] > 0) temp++;
					if ((c < col - 1) && (board[r + 1][c + 1] > 0)) temp++;
				}
				if ((board[r][c]) && ((temp < 2) || (temp > 3))) board[r][c] = 2;
				else if ((!board[r][c]) && (temp == 3)) board[r][c] = -1;
			}
		}

		//第二轮遍历, 回复状态
		for (int r = 0; r < row; ++r)
		{
			for (int c = 0; c < col; ++c)
			{
				if (board[r][c] == 2) board[r][c] = 0;
				else if (board[r][c] == -1) board[r][c] = 1;
			}
		}
	}
};
