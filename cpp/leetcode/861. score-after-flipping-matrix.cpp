#include "public.h"

//4ms, 92.11%
//确保第一列全是1
//其他数0/1个数

//第一列全是1有两种情况一种是当前0都改成1, 一种是当前1都改成0(按行改)

class Solution {
public:
	int matrixScore(vector<vector<int>>& A) {
		//按行调把第一列都弄成1
		for (int r = 0; r < A.size(); ++r)
		{
			if (A[r][0] == 0)
			{
				for (int c = 0; c < A[0].size(); ++c)
				{
					A[r][c] = (A[r][c] == 0) ? 1 : 0;
				}
			}
		}

		//数除第一列外其他列的0或1中个数多的数字个数, 注意: 第一行全是0的情况同时将被考虑, 因为如果所有行都统一翻转, 列的0或1中个数多的数字个数是一样的
		int res = 0;
		res += A.size()*pow(2, A[0].size() - 1);

		for (int c = 1; c < A[0].size(); ++c)
		{
			int zero = 0;
			int one = 0;
			for (int r = 0; r < A.size(); ++r)
			{
				if (A[r][c] == 1) one++;
				else zero++;
			}
			res += max(zero, one)*pow(2, A[0].size() - 1 - c);
		}
		return res;
	}
};
