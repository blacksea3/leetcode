#include "public.h"

//0ms, 100%
//考虑以下思路:迭代二分查找
//当left < right时
//每次求mid, 若nums[mid] > nums[right] 则left = mid + 1
//若nums[mid] < nums[right]则right = mid
//否则(nums[mid] == nums[right])直接right--, 这样将保留能找到的最小值在[left, right-1]间

//最终返回唯一剩下元素left

class Solution {
public:
	int findMin(vector<int>& nums) {
		int le = 0;
		int ri = nums.size() - 1;
		while (le < ri)
		{
			int mid = (le + ri) / 2;
			if (nums[mid] > nums[ri]) le = mid + 1;
			else if (nums[mid] < nums[ri]) ri = mid;
			else ri--;
		}
		return nums[le];
	}
};
