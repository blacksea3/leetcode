#include "public.h"

//60ms, 58.99%
//先扫一遍, 求前n项和对k的取模, 对模分组
//那么大小至少为1, 总和为k的倍数的连续子数组数量就是sum(每个模的数量-1), 如果有模是0的, 还要再加1(补充添加)
//然后再扫一遍, 求出单个数是k的倍数
//根据两个数是否相等决定结果

//注意: 无论k是什么数字都要判断是否有连续的0
//然后如果k是负的就转成正的, k是0不需参与模分组计算

class Solution {
private:
	bool HasConsecutiveZero(const vector<int>& nums)
	{
		for (int index = 0; index < nums.size() - 1; ++index)
		{
			if (nums[index] == nums[index + 1] && nums[index] == 0)
				return true;
		}
		return false;
	}


public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		//判断是否有连续的0
		if (k == 0)
		{
			return HasConsecutiveZero(nums);
		}
		else
		{
			if (HasConsecutiveZero(nums)) return true;

			k = abs(k);
			if (k == 1) return (nums.size() > 1);

			int preSum = 0;
			unordered_map<int, int> modGroup;

			for (auto& num : nums)
			{
				preSum += num;
				modGroup[preSum%k]++;
			}

			int resAll = 0;
			for (auto& m : modGroup)
			{
				if (m.second > 1)
				{
					resAll += m.second - 1;
				}
			}
			if (modGroup.find(0) != modGroup.end()) resAll++;

			for (auto& num : nums)
			{
				if (num%k == 0)
				{
					resAll--;
				}
			}
			return resAll > 0;
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums1 = { 0,1,0 };
	cout << s->checkSubarraySum(nums1, -1);
	vector<int> nums2 = { 1,1 };
	cout << s->checkSubarraySum(nums2, 2);
	return 0;
}
*/
