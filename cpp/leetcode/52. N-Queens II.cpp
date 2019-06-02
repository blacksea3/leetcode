#include "public.h"

//12ms, 56.55%

//similar to problem 51

//DFS(BackTracking) problem, don't need to record the route
//note that the size(n) shall not become very big(>1000), so use recursive solution is ok

class Solution {
private:
	int total_res = 0;

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
			if (isize == (n - 1)) total_res++;
			else DFS(input, n);
			input.pop_back();
		xcontinue: continue;
		}
	}

public:
	int totalNQueens(int n)
	{
		DFS(vector<int>{}, n);
		return total_res;
	}
};
