#include "public.h"

//4ms, 93.27%
//尽管同前, 但是现在不用字符串存储, 而是用二进制位存储棋盘占据情况

class Solution {
private:
	int res = 0;
	int fullcolumns; //二进制n个1

	//p_diagolal:主对角线占据情况, 二进制1为占据, 二进制0为占据, 斜率+45°
	//n_diagonal:次对角线占据情况, 斜率-45°
	//cols:列占据情况
	void DFS(int r, int p_diagonal, int n_diagonal, int cols, int n)
	{
		if (r == n) res++;
		//二进制1为可以用, 0为不能用, 此和传入参数01定义相反
		int emptyCols = fullcolumns & ~(p_diagonal | n_diagonal | cols);

		while (emptyCols > 0)
		{
			int preCol = emptyCols & (-emptyCols); //取二进制最后一个1位
			emptyCols ^= preCol;                   //删除这个可用的1位
			DFS(r + 1, (p_diagonal | preCol) << 1, (n_diagonal | preCol) >> 1, cols | preCol, n);
		}
	}

public:
	int totalNQueens(int n)
	{
		DFS(0, 0, 0, 0, n);
		fullcolumns = (1 << n) - 1;
		return res;
	}
};
