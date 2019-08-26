#include "public.h"

//0ms, 100%
//simple solution
//非递减排序, 然后判断对应位置不相同的人数

class Solution {
public:
	int heightChecker(vector<int>& heights) {
		vector<int> sortedheights = heights;
		sort(sortedheights.begin(), sortedheights.end());

		int count = 0;
		for (int i = 0; i < heights.size(); i++)
			if (heights[i] != sortedheights[i]) count++;
		return count;
	}
};

