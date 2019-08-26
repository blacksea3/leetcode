#include "BinaryTree.h"

//m行n列, O(m*n*n)
//记录每一行的前i列的和
//然后对列进行双循环, 使用unordered_map, 记录前i行, 某一段列的和值, 如果当前前j行的和值sum - target可以找到或者是0, 说明存在i行至j行间, 某一段列, 矩阵和值为target

class Solution {
public:
	int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		int res = 0;

		int rows = matrix.size();
		if (rows == 0) return 0;
		int cols = matrix[0].size();

		//计算前?列的和
		vector<vector<int>> colsum(rows, vector<int>(cols + 1, 0)); //注意colsum[0] = 0, dumpvalue
		for (int row = 0; row < rows; ++row)
		{
			for (int col = 0; col < cols; ++col)
			{
				colsum[row][col + 1] = colsum[row][col] + matrix[row][col];
			}
		}

		for (int colstart = 0; colstart < cols; ++colstart)
		{
			for (int colend = colstart; colend < cols; ++colend)
			{
				for (int rowstart = 0; rowstart < rows; ++rowstart)
				{
					int presum = colsum[rowstart][colend + 1] - colsum[rowstart][colstart];
					if (presum == target) res++;
					for (int rowend = rowstart + 1; rowend < rows; ++rowend)
					{
						presum += colsum[rowend][colend + 1] - colsum[rowend][colstart];
						if (presum == target) res++;
					}
				}
			}
		}
		return res;
	}
};

/*
int main() {
	Solution* s = new Solution();
	vector<vector<int>> matrix = { {0,1,0},{1,1,1},{0,1,0} };
	cout << s->numSubmatrixSumTarget(matrix, 0);



	return 0;
}

*/