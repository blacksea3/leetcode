#include "public.h"

//12ms, 94.67%

//DFS(BackTracking) problem, should record the route
//note that the size(n) shall not become very big(>1000), so use recursive solution is ok

class Solution {
private:
	vector<vector<string>> total_res = {};
	string dumpstr = "";
	void generate_Queens_string(vector<int> input, int n)
	{
		vector<string> returnstr(n, dumpstr);
		for (int i = 0; i < n; i++) returnstr[i][input[i]] = 'Q';
		total_res.push_back(returnstr);
	}

	void DFS(vector<int> input, int n)
	{
		int isize = input.size();
		//remove the same column and (¡À45 degrees) line
		for (int x = 0; x < n; x++)
		{
			for (int i = 0; i < isize; i++)
			{
				if (x == input[i]) goto xcontinue;
				if (x == (input[i] - (isize - i))) goto xcontinue;
				if (x == (input[i] + (isize - i))) goto xcontinue;
			}
			input.push_back(x);
			if (isize == (n - 1)) generate_Queens_string(input, n);
			else DFS(input, n);
			input.pop_back();
		xcontinue: continue;
		}
	}

public:
	vector<vector<string>> solveNQueens(int n)
	{
		for (int i = 0; i < n; i++) dumpstr += ".";

		DFS(vector<int>{}, n);
		return total_res;
	}
};
