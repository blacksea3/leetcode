#include "public.h"

//36ms, 10.31%
//±©Á¦

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int> res;

		for (int i = 0; i < nums1.size(); ++i)
		{
			vector<int>::iterator iter = find(nums2.begin(), nums2.end(), nums1[i]);
			bool isfind = false;
			for (; iter != nums2.end(); ++iter)
				if (*iter > nums1[i])
				{
					res.push_back(*iter);
					isfind = true;
					break;
				}
			if (!isfind) res.push_back(-1);
		}
		return res;
	}
};
