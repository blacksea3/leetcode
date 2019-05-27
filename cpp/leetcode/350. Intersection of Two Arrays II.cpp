#include "public.h"

//8ms, 99.25%

//this is similar to probblem 349, but I use unordered_dict instead of unordered_map

//here, we analyse word frequency of nums1 in a unordered_dict
//then for each num in nums2, operate the unordered_dict of nums1

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> um1;
		for (auto num1 : nums1) um1[num1]++;

		vector<int> res = {};
		for (auto num2 : nums2)
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