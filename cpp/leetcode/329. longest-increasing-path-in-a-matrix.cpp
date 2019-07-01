#include "public.h"

//4ms, 98.91%
//DFS加记忆化
//搜过的地方存储结果, 如果某个未搜过的地方搜到了搜过的地方, 可以直接相加, 这是因为那个搜过的地方的路径绝不可能与当前走过的路径相交(总路径是递增路径)

class Solution {
private:
	int DFS(const vector<vector<int>>& matrix, vector<vector<int>>& memory, int row, int col)
	{
		if (memory[row][col] != -1) return memory[row][col];

		int preval = matrix[row][col];
		int prelen = 1;
		if ((row > 0) && (matrix[row - 1][col] > preval))
			prelen = max(prelen, DFS(matrix, memory, row - 1, col) + 1);
		if ((col > 0) && (matrix[row][col - 1] > preval))
			prelen = max(prelen, DFS(matrix, memory, row, col - 1) + 1);
		if ((row < matrix.size() - 1) && (matrix[row + 1][col] > preval))
			prelen = max(prelen, DFS(matrix, memory, row + 1, col) + 1);
		if ((col < matrix[0].size() - 1) && (matrix[row][col + 1] > preval))
			prelen = max(prelen, DFS(matrix, memory, row, col + 1) + 1);

		memory[row][col] = prelen;
		return prelen;
	}

public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int rows = matrix.size();
		if (!rows) return 0;
		int cols = matrix[0].size();
		if (!cols) return 0;

		vector<vector<int>> memory(rows, vector<int>(cols, -1));

		int res = 0;
		for (int row = 0; row < rows; ++row)
			for (int col = 0; col < cols; ++col)
			{
				res = max(res, DFS(matrix, memory, row, col));
			}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<vector<int>> matrix = { {3,4,5},{3,2,6},{2,2,1} };
	cout << s->longestIncreasingPath(matrix);
	return 0;
}
