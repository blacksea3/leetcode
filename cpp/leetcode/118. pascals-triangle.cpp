#include "public.h"

//simple solution, 4ms, 95.27%

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res = {};
		vector<int> his = {};
		for (int i = 0; i < numRows; ++i)
		{
			vector<int> temp(i + 1, 1);
			for (int j = 1; j < i; ++j)
			{
				temp[j] = his[j - 1] + his[j];
			}
			his = temp;
			res.push_back(temp);
		}
		return res;
	}
};
