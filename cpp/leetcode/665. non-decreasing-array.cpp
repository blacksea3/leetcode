#include "public.h"

//52ms, 24.04%
//一遍扫描, 如果发现num[index] > num[index + 1], 额外查看两个数字, 并且给出修改意见

class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int numsSize = nums.size();
		if (numsSize == 1 || numsSize == 2) return true;
		bool isChanged = false;

		for (int index = 0; index < numsSize - 1; ++index)
		{
			if (nums[index] > nums[index + 1])
			{
				if (isChanged)
					return false;
				else if (index == 0 || nums[index - 1] <= nums[index + 1] ||
					index >= numsSize - 2 || nums[index] <= nums[index + 2])
					isChanged = true;
				else
					return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> nums1 = { 2,3,3,2,4 };
	cout << s->checkPossibility(nums1);
	vector<int> nums2 = { 4, 2, 3 };
	cout << s->checkPossibility(nums2);
	return 0;
}
