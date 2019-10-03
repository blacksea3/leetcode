#include "public.h"

//24ms, 98.46%
//和上一题差不多一个意思
//变成4个矩形

class NumMatrix {
private:
	vector<vector<int>> prev;
public:
	NumMatrix(vector<vector<int>>& matrix) {
		if ((matrix.size() == 0) || (matrix[0].size() == 0)) return;

		vector<int> temp(matrix[0].size() + 1);
		prev.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));

		for (int row = 1; row <= matrix.size(); ++row)
		{
			int presum = 0;
			for (int col = 1; col <= matrix[0].size(); ++col)
			{
				presum += matrix[row - 1][col - 1];
				prev[row][col] = prev[row - 1][col] + presum;
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return prev[row2 + 1][col2 + 1] - prev[row2 + 1][col1] - prev[row1][col2 + 1] + prev[row1][col1];
	}
};
