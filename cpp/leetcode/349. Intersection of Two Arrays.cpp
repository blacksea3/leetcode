#include "public.h"

//8ms, 96.45%
//统计nums1的各个数字, 然后对nums2进行分析
//注:重复数字不重复统计

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> um1(nums1.begin(), nums1.end());

		vector<int> res = {};
		unordered_set<int>::iterator iter;
		for (auto& num2 : nums2)
		{
			iter = um1.find(num2);
			if (iter != um1.end())
			{
				res.emplace_back(num2);
				um1.erase(iter);
			}
		}
		return res;
	}
};
