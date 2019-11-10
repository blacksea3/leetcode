#include "public.h"

//
//贪婪, 先判断upper+lower和colsum和
//然后对2, 全放1, 然后对1, 按次序放

class Solution {
public:
	vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
		int tot = accumulate(colsum.begin(), colsum.end(), (int)0);
		if ((upper + lower) != tot) return vector<vector<int>>{};
		else
		{
			int colSize = colsum.size();
			vector<vector<int>> res(2, vector<int>(colSize, 0));
			for (int index = 0; index < colSize; ++index)
			{
				if (colsum[index] == 2)
				{
					upper--;
					lower--;
					res[0][index] = 1;
					res[1][index] = 1;
				}
			}
			if (upper < 0) return vector<vector<int>>{};
			for (int index = 0; index < colSize; ++index)
			{
				if (colsum[index] == 1)
				{
					if (upper > 0)
					{
						upper--;
						res[0][index] = 1;
					}
					else
					{
						lower--;
						res[1][index] = 1;
					}
				}
			}
			return (upper == 0) ? res : vector<vector<int>>{};
		}
	}
};
