#include "public.h"

//12ms, 96.75%

//here, we analyse word frequency of nums1 in a unordered_set
//then for each num in nums2, operate the unordered_set of nums1

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> um1;
		for (auto num1 : nums1) um1.insert(num1);

		vector<int> res = {};
		unordered_set<int>::iterator iter;
		for (auto num2 : nums2)
		{
			iter = um1.find(num2);
			if (iter != um1.end())
			{
				res.push_back(num2);
				um1.erase(iter);
			}
		}
		return res;
	}
};
