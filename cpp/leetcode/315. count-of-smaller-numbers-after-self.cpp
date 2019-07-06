#include "public.h"

//40ms, 94.04%
//归并排序-力扣官方题解

class Solution {
private:
	void helper(const vector<int>& nums, int left, int right, vector<int>& temp,
		vector<int>& indexes, vector<int>& res)
	{
		if (left == right) return;
		int mid = left + (right - left) / 2;

		//分治左右两半
		helper(nums, left, mid, temp, indexes, res);
		helper(nums, mid + 1, right, temp, indexes, res);

		if (nums[indexes[mid]] <= nums[indexes[mid + 1]])
			return;
		sort_and_count_smaller(nums, left, mid, right, temp, indexes, res);
	}

	void sort_and_count_smaller(const vector<int>& nums, int left, int mid, int right,
		vector<int>& temp, vector<int>& indexes, vector<int>& res)
	{
		//[left, mid]前有序数组
		//[mid+1, right]后有序数组

		//copy
		for (int i = left; i <= right; ++i) temp[i] = indexes[i];

		int l = left;
		int r = mid + 1;

		for (int i = left; i <= right; ++i)
		{
			if (l > mid)
			{
				// l 用完，就拼命使用 r
				// [1,2,3,4] [5,6,7,8]
				indexes[i] = temp[r];
				r += 1;
			}
			else if (r > right)
			{
				// r 用完，就拼命使用 l
				// [6,7,8,9] [1,2,3,4]
				indexes[i] = temp[l];
				l += 1;
				// 注意：此时前面剩下的数，比后面所有的数都大
				res[indexes[i]] += (right - mid);
			}
			else if (nums[temp[l]] <= nums[temp[r]])
			{
				// [3,5,7,9] [4,6,8,10]
				indexes[i] = temp[l];
				l += 1;
				// 注意：
				res[indexes[i]] += (r - mid - 1);
			}
			else
			{
				//assert nums[temp[l]] > nums[temp[r]]
				// 上面两种情况只在其中一种统计就可以了
				// [3,5,7,9] [4,6,8,10]
				indexes[i] = temp[r];
				r += 1;
			}
		}

	}


public:
	vector<int> countSmaller(vector<int>& nums) {
		int size = nums.size();
		if (size == 0) return {};
		else if (size == 1) return { 0 };
		else
		{
			vector<int> temp(size, 0);
			vector<int> indexes(size);
			for (int i = 0; i < size; ++i)
				indexes[i] = i;
			vector<int> res(size, 0);
			helper(nums, 0, size - 1, temp, indexes, res);
			return res;
		}
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> nums = {2,1};
	vector<int> res = s->countSmaller(nums);
	return 0;
}
