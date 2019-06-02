#include "public.h"

//40ms, 85.96%

//This is a DFS(BackTracking) problem

class Solution {
private:
	//here x means line, y means column
	//note that: if can use const or/and &, just use it to make the algorithm faster
	bool DFS(const vector<vector<char>>& board, vector<vector<bool>>& isused, int prex, int prey, const int& maxx, const int& maxy, const string& preword, int sloc)
	{
		if (board[prex][prey] == preword[sloc])
		{
			if (preword.size() == sloc + 1) return true;
			isused[prex][prey] = true;
			if (prex != 0) if (!isused[prex - 1][prey]) if (DFS(board, isused, prex - 1, prey, maxx, maxy, preword, sloc + 1)) return true;
			if (prey != 0) if (!(isused[prex][prey - 1])) if (DFS(board, isused, prex, prey - 1, maxx, maxy, preword, sloc + 1)) return true;
			if (prex != maxx) if (!(isused[prex + 1][prey])) if (DFS(board, isused, prex + 1, prey, maxx, maxy, preword, sloc + 1)) return true;
			if (prey != maxy) if (!(isused[prex][prey + 1])) if (DFS(board, isused, prex, prey + 1, maxx, maxy, preword, sloc + 1)) return true;
			isused[prex][prey] = false;
		}
		return false;
	}
public:
	bool exist(vector<vector<char>>& board, string word) {
		//
		int maxline = board.size();
		if (maxline == 0) return false;
		int maxcolumn = board[0].size();
		if (maxcolumn == 0) return false;
		vector<vector<bool>> isused(maxline, vector<bool>(maxcolumn, false));

		for (int i = 0; i < maxline; i++)
			for (int j = 0; j < maxcolumn; j++)
			{
				if (DFS(board, isused, i, j, maxline - 1, maxcolumn - 1, word, 0)) return true;
			}
		return false;
	}
};
