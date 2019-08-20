#include "public.h"

//40ms, 86.95%
//用下标存数据: nums[index]存index + 1,
//再遍历一次数组找到数据不对应的位置, 对应缺失的数字和重复的数字

class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		int numsSize = nums.size();
		int duplicate;
		int notfound;

		for (int index = 0; index < numsSize; ++index)
		{
			while (nums[index] != index + 1 && nums[nums[index] - 1] != nums[index])
			{
				swap(nums[index], nums[nums[index] - 1]);
			}
		}

		for (int index = 0; index < numsSize; ++index)
		{
			if (nums[index] != index + 1)
			{
				notfound = index + 1;
				duplicate = nums[index];
				break;
			}
		}
		return { duplicate, notfound };
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 1,2,2,4 };
	auto res = s->findErrorNums(nums);
	return 0;
}
*/
