#include "public.h"

//8ms, 96.03%
//统计nums1的数字次数, 然后和nums2比较

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> um1;
		for (auto& num1 : nums1) um1[num1]++;

		vector<int> res = {};
		for (auto& num2 : nums2)
		{
			if (um1[num2] != 0)
			{
				um1[num2]--;
				res.push_back(num2);
			}
		}
		return res;
	}
};
