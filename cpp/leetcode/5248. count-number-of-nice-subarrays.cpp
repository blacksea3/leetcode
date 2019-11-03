#include "public.h"

//
//滑动窗口
//转成一个数组, 假设num是偶数个数,1个奇数,偶数个数...
//计算偶数个数得到数组

class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		vector<int> even;

		int preE = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] % 2)
			{
				even.emplace_back(preE);
				preE = 0;
			}
			else preE++;
		}

		int res = 0;

		for (int left = 0; left < even.size() - k; ++left)
		{
			int right = left + k;
			res += (even[left] + 1)*(even[right] + 1);
		}
		return res;
	}
};
