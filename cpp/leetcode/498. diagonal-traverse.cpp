#include "public.h"

//172ms, 28.50%
//模拟

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return {};

		vector<int> res;
		int M = matrix.size();
		int N = matrix[0].size();
		int preR = 0;
		int preC = 0;
		bool isRightUp = true;

		//会自动越界, 从而退出循环
		while (preR < M && preC < N)
		{
			res.push_back(matrix[preR][preC]);
			if (isRightUp)
			{
				if (preC == N - 1)
				{
					preR++;
					isRightUp = false;
				}
				else if (preR == 0)
				{
					preC++;
					isRightUp = false;
				}
				else
				{
					preC++;
					preR--;
				}
			}
			else
			{
				if (preR == M - 1)
				{
					preC++;
					isRightUp = true;
				}
				else if (preC == 0)
				{
					preR++;
					isRightUp = true;
				}
				else
				{
					preR++;
					preC--;
				}
			}
		}
		return res;
	}
};
