#include "public.h"

//二分查找,注意数组中无重复元素,8ms, 83.60%

class Solution {
private:
	//确保输入不为空nums, start和end都是下标
	int iter_findMin(vector<int>& nums, int start, int end)
	{
		//二分查找
		if (nums[start] <= nums[end]) //这里合并了了num只有一个元素的条件
			return nums[start];
		else
		{
			int mid = (start + end) / 2;  //当num长度>=2时,拆成下标start至min 与 min+1至end进行判断
			if (nums[start] <= nums[mid])
				return iter_findMin(nums, mid + 1, end);
			else
				return iter_findMin(nums, start, mid);
		}
	}

public:
	int findMin(vector<int>& nums) {
		//看起来题目绝不会输入空数组
		return iter_findMin(nums, 0, nums.size() - 1);
	}
};