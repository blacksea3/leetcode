#include "public.h"

//12ms, 91.95%
//б������, ����ʵ����ֻ��Ҫ������һ����ʼ�ĺ͵�һ����ʼ�ľͿ���

class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {


		for (int c = 0; c < matrix[0].size(); ++c)
		{
			int startnum = matrix[0][c];
			int prec = c + 1;
			int prer = 1;
			while (prec < matrix[0].size() && prer < matrix.size())
			{
				if (matrix[prer][prec] != startnum) return false;
				prec++;
				prer++;
			}
		}

		for (int r = 1; r < matrix.size(); ++r)
		{
			int startnum = matrix[r][0];
			int prec = 1;
			int prer = r + 1;
			while (prec < matrix[0].size() && prer < matrix.size())
			{
				if (matrix[prer][prec] != startnum) return false;
				prec++;
				prer++;
			}
		}
		return true;
	}
};
