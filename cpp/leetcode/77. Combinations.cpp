#include "public.h"

//108ms, 88.23%

//This is a BackTracking problem
//Solve it recursively

class Solution {
private:
	vector<vector<int>> res;
	void recu_combine(int pren, int totaln, int prek, vector<int> prev)
	{
		for (int i = pren + 1; i <= (totaln - prek + 1); ++i)
		{
			prev.push_back(i);
			if (prek == 1) res.push_back(prev);
			else recu_combine(i, totaln, prek - 1, prev);
			prev.pop_back();
		}
	}

public:
	vector<vector<int>> combine(int n, int k) {
		recu_combine(0, n, k, {});
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> res = s->combine(1, 1);
	return 0;
}
*/