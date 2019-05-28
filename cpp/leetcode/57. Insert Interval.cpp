#include "public.h"

//28ms, 64.10%

//brute force, traverse the intervals

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> res;
		bool merge = false;
		for (auto & i : intervals) {
			if (i[1] < newInterval[0]) {
				res.push_back(i);
			}
			else if (i[0] > newInterval[1]) {
				if (!merge) {
					merge = true;
					res.push_back(newInterval);
				}
				res.push_back(i);
			}
			else {
				newInterval[0] = min(i[0], newInterval[0]);
				newInterval[1] = max(i[1], newInterval[1]);
			}
		}
		if (!merge) res.push_back(newInterval);
		return res;
	}
};