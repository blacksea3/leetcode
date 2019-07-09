#include "public.h"

//24ms, 95.48%
//多指针, DP problem

class Solution {
public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		if ((!nums1.size()) || (!nums2.size())) return {};

		vector<vector<int>> res(min((size_t)k, nums1.size()*nums2.size()));
		//使nums1更短, 先不这样做, 做的话后面也需要修改
		//if (nums1.size() > nums2.size()) swap(nums1, nums2);

		multimap<int, int> sorted_value_with_loc1;
		vector<int> loc2(nums1.size(), 0);
		//init
		for (int i = 0; i < nums1.size(); ++i)
		{
			sorted_value_with_loc1.insert(pair<int, int>{nums2[0] + nums1[i], i});
		}

		//连续更新
		for (int i = 0; i < min((size_t)k, nums1.size()*nums2.size()); ++i)
		{
			pair<int, int> presum = *sorted_value_with_loc1.begin();
			res[i] = { nums1[presum.second], nums2[loc2[presum.second]] };
			sorted_value_with_loc1.erase(sorted_value_with_loc1.begin());
			loc2[presum.second]++;
			if (loc2[presum.second] < nums2.size()) sorted_value_with_loc1.insert(pair<int, int>{nums2[loc2[presum.second]] + nums1[presum.second], presum.second});
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums1 = { 1,2 };
	vector<int> nums2 = { 3 };
	auto res = s->kSmallestPairs(nums1, nums2, 3);
	return 0;
}
*/
