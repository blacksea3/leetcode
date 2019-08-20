#include "public.h"

//192ms, 99.01%
//Ä£Äâ

class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		int lineCount = M.size();
		int colCount = M[0].size();

		vector<vector<int>> res(lineCount, vector<int>(colCount));

		for (int line = 0; line < lineCount; ++line)
		{
			for (int col = 0; col < colCount; ++col)
			{
				int sum = M[line][col];
				int count = 1;

				if (line > 0)
				{
					if (col > 0)
					{
						sum += M[line - 1][col - 1];
						count++;
					}
					if (col < colCount - 1)
					{
						sum += M[line - 1][col + 1];
						count++;
					}
					sum += M[line - 1][col];
					count++;
				}
				if (line < lineCount - 1)
				{
					if (col > 0)
					{
						sum += M[line + 1][col - 1];
						count++;
					}
					if (col < colCount - 1)
					{
						sum += M[line + 1][col + 1];
						count++;
					}
					sum += M[line + 1][col];
					count++;
				}
				if (col > 0)
				{
					sum += M[line][col - 1];
					count++;
				}
				if (col < colCount - 1)
				{
					sum += M[line][col + 1];
					count++;
				}
				res[line][col] = sum / count;
			}
		}
		return res;
	}
};
