#include "public.h"

//28ms, 94.07%
//DFS
class Solution {
private:
	bool DFS(const vector<vector<char>>& board, vector<vector<bool>>& isused, int r, int c, int maxr, int maxc, const string& preword, int sloc)
	{
		if (board[r][c] == preword[sloc])
		{
			if (preword.size() == sloc + 1) return true;
			isused[r][c] = true;
			if (r > 0) if (!isused[r - 1][c]) if (DFS(board, isused, r - 1, c, maxr, maxc, preword, sloc + 1)) return true;
			if (c > 0) if (!(isused[r][c - 1])) if (DFS(board, isused, r, c - 1, maxr, maxc, preword, sloc + 1)) return true;
			if (r < maxr - 1) if (!(isused[r + 1][c])) if (DFS(board, isused, r + 1, c, maxr, maxc, preword, sloc + 1)) return true;
			if (c < maxc - 1) if (!(isused[r][c + 1])) if (DFS(board, isused, r, c + 1, maxr, maxc, preword, sloc + 1)) return true;
			isused[r][c] = false;
		}
		return false;
	}
public:
	bool exist(vector<vector<char>>& board, string word) {
		int maxr = board.size();
		if (maxr == 0) return false;
		int maxc = board[0].size();
		if (maxc == 0) return false;
		vector<vector<bool>> isused(maxr, vector<bool>(maxc, false));

		for (int i = 0; i < maxr; i++)
			for (int j = 0; j < maxc; j++)
			{
				if (DFS(board, isused, i, j, maxr, maxc, word, 0)) return true;
			}
		return false;
	}
};
