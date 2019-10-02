#include "public.h"

//二分查找, 4ms, 97.09%
//如果nums[mid] < nums[mid+1]在mid+1至end出现峰值元素 left = mid + 1
//否则start至mid一定有元素
//注意相邻的元素不同

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left < right)
		{
			mid = (right + left) / 2;
			if (nums[mid] < nums[mid + 1])
				left = mid + 1;
			else
				right = mid;
		}

		return left;

	}
};
