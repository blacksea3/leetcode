#include "public.h"

//108ms, 31.45%
//一套DFS解决, 从边界DFS, 对于能接触到的陆地都改成海水!
//最后再获取陆地数量

class Solution {
private:
	void DFS(vector<vector<int>>& A, int r, int c)
	{
		A[r][c] = 0;
		if (r > 0 && A[r - 1][c] == 1) DFS(A, r - 1, c);
		if (c > 0 && A[r][c - 1] == 1) DFS(A, r, c - 1);
		if (r < A.size() - 1 && A[r + 1][c] == 1) DFS(A, r + 1, c);
		if (c < A[0].size() - 1 && A[r][c + 1] == 1) DFS(A, r, c + 1);
	}


public:
	int numEnclaves(vector<vector<int>>& A) {

		for (int r = 0; r < A.size(); ++r)
		{
			if (A[r][0] == 1) DFS(A, r, 0);
			if (A[r][A[0].size() - 1] == 1) DFS(A, r, A[0].size() - 1);
		}

		for (int c = 0; c < A[0].size(); ++c)
		{
			if (A[0][c] == 1) DFS(A, 0, c);
			if (A[A.size() - 1][c] == 1) DFS(A, A.size() - 1, c);
		}

		int res = 0;
		for (int r = 0; r < A.size(); ++r)
			for (int c = 0; c < A[0].size(); ++c)
				if (A[r][c] == 1) res++;

		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	//vector<vector<int>> A = { {0,0,1,1,0,0,0,0,0,1},{1,1,0,1,0,0,1,0,0,1},{1,1,0,0,1,0,1,1,0,0},{1,0,0,1,0,0,0,0,0,1},{0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{1,0,1,0,1,1,1,0,1,0},{0,1,1,1,0,0,1,0,0,1},{0,1,1,0,0,1,0,1,1,0},{1,0,1,1,0,0,1,1,0,0},{1,0,1,0,1,1,1,0,0,1} };
	vector<vector<int>> A = { {0,0,0,1,1,1,0,1,0,0},{1,1,0,0,0,1,0,1,1,1},{0,0,0,1,1,1,0,1,0,0},{0,1,1,0,0,0,1,0,1,0},{0,1,1,1,1,1,0,0,1,0},{0,0,1,0,1,1,1,1,0,1},{0,1,1,0,0,0,1,1,1,1},{0,0,1,0,0,1,0,1,0,1},{1,0,1,0,1,1,0,0,0,0},{0,0,0,0,1,1,0,0,0,1} };
	auto res = s->numEnclaves(A);
	return 0;
}
