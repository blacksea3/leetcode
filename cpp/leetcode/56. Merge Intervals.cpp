#include "public.h"

//48ms, 26.09%

//sort by left border first, then merge one and one intervals, need only one traverse

class Solution {
private:
	bool LessEqSort(const vector<int> &i1, const vector<int> &i2)
	{
		return (i1[0] <= i2[0]);
	}
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		//special input
		if (intervals.size() == 0) return vector<vector<int>>{};

		//sort by left border
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