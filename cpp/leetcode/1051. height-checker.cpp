#include "public.h"

//0ms, 100%
//simple solution
//�ǵݼ�����, Ȼ���ж϶�Ӧλ�ò���ͬ������

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

