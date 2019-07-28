#include "public.h"

//664ms, 5.00%
//为了简单起见: 把两座岛的各个点全部指出来, 然后求距离即可

class Solution {
private:
	void changecolor(vector<vector<int>>& A, int r, int c)
	{
		A[r][c] = 2;
		if (r > 0 && A[r - 1][c] == 1) changecolor(A, r - 1, c);
		if (c > 0 && A[r][c - 1] == 1) changecolor(A, r, c - 1);
		if (r < A.size() - 1 && A[r + 1][c] == 1) changecolor(A, r + 1, c);
		if (c < A[0].size() - 1 && A[r][c + 1] == 1) changecolor(A, r, c + 1);
	}


public:
	int shortestBridge(vector<vector<int>>& A) {
		//把其中一座从1改成2
		for (int r = 0; r < A.size(); ++r)
		{
			for (int c = 0; c < A[0].size(); ++c)
			{
				if (A[r][c] == 1)
				{
					changecolor(A, r, c);
					goto bigbreak;
				}
			}
		}
	bigbreak:

		//找到两座岛的所有点
		vector<vector<int>> dao1;
		vector<vector<int>> dao2;

		for (int r = 0; r < A.size(); ++r)
		{
			for (int c = 0; c < A[0].size(); ++c)
			{
				if (A[r][c] == 1) dao1.push_back({ r,c });
				else if (A[r][c] == 2) dao2.push_back({ r,c });
			}
		}

		//求距离
		int res = INT_MAX;
		for (auto& d1 : dao1)
		{
			for (auto& d2 : dao2)
			{
				res = min(res, abs(d1[0] - d2[0]) + abs(d1[1] - d2[1]) - 1);
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> A = { {0,1},{1,0} };
	auto res = s->shortestBridge(A);
	return 0;
}
*/
