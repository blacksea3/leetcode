#include "public.h"

//68ms, 11.32%
//强行模拟一波
//vector<vector<int>> glass(100, vector<int>(100, 0));
//init: glass[0][0] = poured;
//按层向下: glass[i][j] = 0.5*(glass[i-1][j-1]-1) + 0.5*(glass[i-1][j]-1), 如果上一层对应位置能>1得话, 否则是0
//  glass[i][0] = 0.5(glass[i-1][0]-1), glass[i][i]=0.5(glass[i-1][i-1]-1)

class Solution {
public:
	double champagneTower(int poured, int query_row, int query_glass) {
		vector<vector<double>> glass(100, vector<double>(100, 0));

		glass[0][0] = poured;

		for (int i = 1; i <= 99; ++i)
		{
			//复制一份
			vector<double> cpglass(i);
			for (int j = 0; j <= i - 1; ++j)
			{
				cpglass[j] = glass[i - 1][j];
			}

			if (glass[i - 1][0] > 1)
			{
				cpglass[0] = 1;
				glass[i][0] = 0.5*(glass[i - 1][0] - 1);
			}
			else glass[i][0] = 0;

			for (int j = 1; j <= i - 1; ++j)
			{
				double pre = 0;
				if (glass[i - 1][j - 1] > 1)
				{
					cpglass[j - 1] = 1;
					pre += 0.5*(glass[i - 1][j - 1] - 1);
				}
				if (glass[i - 1][j] > 1)
				{
					cpglass[j] = 1;
					pre += 0.5*(glass[i - 1][j] - 1);
				}
				glass[i][j] = pre;
			}

			if (glass[i - 1][i - 1] > 1)
			{
				cpglass[i - 1] = 1;
				glass[i][i] = 0.5*(glass[i - 1][i - 1] - 1);
			}
			else glass[i][i] = 0;

			//复制回去
			for (int j = 0; j <= i - 1; ++j)
			{
				glass[i - 1][j] = cpglass[j];
			}
		}

		return glass[query_row][query_glass];
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->champagneTower(6, 3, 2);
	return 0;
}
*/
