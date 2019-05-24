#include "public.h"

//4ms, 99.98%

//binary search

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		//special input
		int nsize = nums.size();
		if (nsize == 0) return 0;
		if (nsize == 1) return (nums[0] >= target) ? 0 : 1;

		//border conditions
		if (nums[0] > target) return 0;
		if (nums[nsize - 1] < target) return nsize;

		//main binary search
		int left = 0;
		int right = nsize - 1;

		while (left < right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] < target) left = mid + 1;
			else if (nums[mid] > target) right = mid - 1;
			else
				return mid;
		}

		if (left != right)  //at this time right == left - 1
		{
			if (nums[right] > target) return right;
			else if (nums[left] > target) return left;
			else return left + 1;
		}
		else
		{
			return (nums[left] >= target) ? left : left + 1;
		}
	}
};