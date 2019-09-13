#include "public.h"

//4ms, 99.88%
//λ����: ��������0 �� (nums.size() - 1) ������, ������λ1��ʾѡȡ, 0��ʾ��ѡȡ

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
