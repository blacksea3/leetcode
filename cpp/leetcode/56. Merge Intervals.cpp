#include "public.h"

//28ms, 79.66%
//先按左边界排序, 然后一边扫描同时合并

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int iSize = intervals.size();
		if (iSize == 0) return vector<vector<int>>{};

		sort(intervals.begin(), intervals.end());
		vector<vector<int>> res = { intervals[0] };

		for (int i = 1; i < intervals.size(); i++)
		{
			if (res[res.size() - 1][1] >= intervals[i][0])
				res[res.size() - 1][1] = max(intervals[i][1], res[res.size() - 1][1]);
			else
				res.push_back(intervals[i]);
		}
		return res;
	}
};