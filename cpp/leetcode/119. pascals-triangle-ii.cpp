#include "public.h"

//0ms, 100%
//模拟, 原地合并

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> his = { 1 };
		for (int i = 0; i < rowIndex; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				his[j] += his[j + 1];
			}
			his.insert(his.begin(), 1);
		}
		return his;
	}
};
