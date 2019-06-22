#include "public.h"

//类似153，只不过可能有重复元素, 12ms 78.06%

class Solution {
public:
	int iter_findMin(vector<int>& nums, int start, int end)
	{
		//二分查找
		if (start == end)  //一个元素
			return nums[start];
		else
		{
			if (nums[start] < nums[end])
			{
				return nums[start];
			}
			else if (nums[start] > nums[end])
			{
				int mid = (start + end) / 2;  //当num长度>=2时,拆成下标start至min 与 min+1至end进行判断
				if (nums[start] <= nums[mid])   //形如 2 2 2 3 1或者  2 2 2 0 1都不要紧,合并进去
					return iter_findMin(nums, mid + 1, end);
				else
					return iter_findMin(nums, start, mid);
			}
			else   //要搞清楚2 3 0 1 2或者 2 2 2 2 2 或者 2 3 4 1 2
			{
				//简单点,O(n)遍历吧
				for (int i = start; i <= end; i++)
				{
					if (nums[i] < nums[start])
						return nums[i];
					else if (nums[i] > nums[start])
					{
						return iter_findMin(nums, i, end);
					}
					else;
				}
				return nums[start];
			}
		}
	}


public:
	int findMin(vector<int>& nums) {
		return iter_findMin(nums, 0, nums.size() - 1);
	}
};
