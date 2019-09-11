#include "public.h"

//4ms, 97.01%
//模拟

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int dir = 0; //0right 1down 2left 3up

		int m = matrix.size();
		if (m == 0) return vector<int>{};
		int n = matrix[0].size();
		if (n == 0) return vector<int>{};

		//四个方向的移动
		int left_border = 0;
		int right_border = n - 1;
		int up_border = 0;
		int down_border = m - 1;
		int prex = 0;
		int prey = 0;
		vector<int> res(m*n, 0);
		int count = 0;
		while (true)
		{
			for (int i = left_border; i <= right_border; ++i) res[count++] = matrix[up_border][i];
			if (up_border++ >= down_border) break;
			for (int i = up_border; i <= down_border; ++i) res[count++] = matrix[i][right_border];
			if (left_border >= right_border--) break;
			for (int i = right_border; i >= left_border; --i) res[count++] = matrix[down_border][i];
			if (up_border >= down_border--) break;
			for (int i = down_border; i >= up_border; --i) res[count++] = matrix[i][left_border];
			if (left_border++ >= right_border) break;
		}
		return res;
	}
};