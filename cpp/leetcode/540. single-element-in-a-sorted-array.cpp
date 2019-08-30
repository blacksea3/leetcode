#include "public.h"

//12ms, 82.39%
//二分
//通过当前元素是否有重复的, 以及下标来决定重复元素值更小还是更大
//题意: 一定存在这样的数字
//在递归的过程中, 隐藏这样的条件: left至right, 左闭右闭, 个数一定是奇数

class Solution {
private:
	int recu(const vector<int>& nums, int left, int right)
	{
		if (left > right) return -999;  //error value
		else if (left == right) return nums[left];

		int mid = (left + right) / 2;
		if (nums[mid] == nums[mid - 1])
		{
			if (mid % 2 == 0)
			{
				return recu(nums, left, mid - 2);
			}
			else
			{
				return recu(nums, mid + 1, right);
			}
		}
		else if (nums[mid] == nums[mid + 1])
		{
			if (mid % 2 == 0)
			{
				return recu(nums, mid + 2, right);
			}
			else
			{
				return recu(nums, left, mid - 1);
			}
		}
		else return nums[mid];
	}

public:
	int singleNonDuplicate(vector<int>& nums) {
		return recu(nums, 0, nums.size() - 1);
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = {1,1,2,3,3,4,4,8,8};
	cout << s->singleNonDuplicate(nums);
	return 0;
}
*/
