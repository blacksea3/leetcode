#include "public.h"

//84ms, 59.64%
//暴力
//还能重复的?

class Solution {
public:
	int numEquivDominoPairs(vector<vector<int>>& dominoes) {
		//统计
		vector<vector<int>> v(10, vector<int>(10, 0));

		for (auto& d : dominoes)
		{
			v[d[0]][d[1]]++;
		}

		int res = 0;

		for (int i = 2; i <= 9; ++i)
		{
			for (int j = 1; j < i; ++j)
			{
				res += v[j][i] * v[i][j];
			}
		}

		for (int i = 1; i <= 9; ++i)
		{
			for (int j = 1; j <= 9; ++j)
			{
				res += v[i][j] * (v[i][j] - 1) / 2;
			}
		}

		return res;
	}
};
