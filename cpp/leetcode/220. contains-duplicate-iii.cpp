#include "public.h"

//12ms, 90.63%
//见注释

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		//另一种暴力求解,先按值排序,同时记录排序后的对应下标
		//O(n^2)
		if (k < 1) return false;
		if (t < 0) return false;

		vector<pair<int, int>> vp(nums.size(), pair<int, int> {});
		for (int i = 0; i < nums.size(); ++i)
			vp[i] = pair<int, int>{ nums[i],i };

		sort(vp.begin(), vp.end());

		int j = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			while ((j < i) && ((vp[j].first + t) < vp[i].first))
				j++;
			for (int m = j; m < i; m++)
				if (abs(vp[m].second - vp[i].second) <= k)
					return true;
		}
		return false;
	}
};
