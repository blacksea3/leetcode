#include "public.h"

//4ms, 90.72%
//二分查找, 数组中无重复元素

class Solution {
private:
	//确保输入不为空nums, start和end都是下标
	int mBinarySearch(vector<int> const& nums, int start, int end)
	{
		//二分查找
		if (nums[start] <= nums[end]) //num只有一个元素或者当前已排序
			return nums[start];
		else
		{
			int mid = (start + end) / 2;  //当num长度>=2时,拆成下标start至min 与 min+1至end进行判断
			if (nums[start] <= nums[mid])
				return mBinarySearch(nums, mid + 1, end);
			else
				return mBinarySearch(nums, start, mid);
		}
	}

public:
	int findMin(vector<int>& nums) {
		//看起来题目绝不会输入空数组
		return mBinarySearch(nums, 0, nums.size() - 1);
	}
};
