#include "public.h"

//92.17%

//traverse the bits of nums.size(), 1 means select a num, 0 means don't select

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int nsize = nums.size();
		if (nsize == 0) return vector<vector<int>> {};

		int length = (int)pow(2, nsize);

		vector<vector<int>> res(length, vector<int> {});

		for (int i = 0; i < length; i++)
		{
			vector<int> temp = {};
			for (int j = 0; j < nsize; j++)
			{
				if ((i >> j) % 2 == 1) temp.push_back(nums[j]);
			}
			res[i] = temp;
		}
		return res;
	}
};