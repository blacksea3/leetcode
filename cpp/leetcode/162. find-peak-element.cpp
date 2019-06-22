#include "public.h"

//二分查找, 4ms, 99.16%

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		//二分搜索
		//注意到:   nums[mid] < nums[mid+1]   1 4 3 2 1  不管如何, 总会在mid+1至end出现峰值元素
		//这是因为mid+1至end比左右两端都大
		//否则start至mid一定有元素

		//注意相邻的元素不同

		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left < right)
		{
			mid = left + (right - left) / 2;
			if (nums[mid] < nums[mid + 1])
				left = mid + 1;
			else
				right = mid;
		}

		return left;

	}
};
