#include "public.h"

//12ms, 92.87%
//暴力, DFS

class Solution {
private:
	bool isok = false;
	void DFS(const vector<int>& nums, int lastloc, int target)
	{
		if (isok) return;
		if (target <= nums[lastloc + 1]) //如果target小于可搜索的值上限, 则二分查找
		{
			if (binary_search(nums.cbegin() + lastloc + 1, nums.cend(), target, greater<int>()))
				isok = true;
		}
		else
		{
			int remainsum = accumulate(nums.cbegin() + lastloc + 1, nums.cend(), 0);
			for (int i = lastloc + 1; i < nums.size(); ++i)
			{
				if (target > remainsum) return;
				DFS(nums, i, target - nums[i]);
				remainsum -= nums[i];
			}
		}
	}

public:
	bool canPartition(vector<int>& nums) {
		int sum = accumulate(nums.cbegin(), nums.cend(), 0);

		if (sum % 2) return false;
		else
		{
			sort(nums.begin(), nums.end(), greater<int>()); //降序排序, 加快DFS搜索
			DFS(nums, -1, sum / 2);
			return isok;
		}
	}
};
