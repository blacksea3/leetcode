#include "public.h"

//4ms, 99.88%
//位运算: 遍历所有0 至 (nums.size() - 1) 的数字, 二进制位1表示选取, 0表示不选取

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int nsize = nums.size();
		int length = (int)pow(2, nsize);

		vector<vector<int>> res(length);

		for (int i = 0; i < length; i++)
		{
			vector<int> temp = {};
			for (int j = 0; j < nsize; j++)
			{
				if ((i >> j) % 2 == 1) temp.emplace_back(nums[j]);
			}
			res[i] = temp;
		}
		return res;
	}
};
