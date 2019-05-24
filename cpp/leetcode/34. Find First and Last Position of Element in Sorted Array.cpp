#include "public.h"

//8ms, 99.50%

//find target first
// then find left border and right border

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		//binary search
		vector<int> res = { -1,-1 };
		int nsize = nums.size();
		if (nsize == 0) return res;
		else if (nsize == 1) return (target == nums[0]) ? vector<int> {0, 0} : res;
		else
		{
			int left = 0;
			int right = nsize - 1;
			while (left <= right)
			{
				int mid = (left + right) / 2;
				if (nums[mid] < target) left = mid + 1;
				else if (nums[mid] > target) right = mid - 1;
				else  //border_expand search
				{
					//[left, mid-1], [mid + 1, right], here mid+-1可能超出边界
					if ((mid == left) || (nums[mid - 1] != target))
						res[0] = mid;
					else
						res[0] = search_fix_right_border(nums, target, left, mid - 1);
					if ((mid == right) || (nums[mid + 1] != target))
						res[1] = mid;
					else
						res[1] = search_fix_left_border(nums, target, mid + 1, right);
					return res;
				}
			}
			return res;
		}
	}

	//fix right border, right border must == target, find the most left == target, nums should be incremently sorted
	int search_fix_right_border(vector<int>& nums, int target, int startloc, int endloc)
	{
		int left = startloc;
		int right = endloc;
		int res = 0;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] < target) left = mid + 1;
			else
			{
				if (mid == left)
				{
					res = left;
					break;
				}
				else if (nums[mid - 1] != target)
				{
					res = mid;
					break;
				}
				else right = mid - 1;
			}
		}
		return res;
	}

	//fix left border, left border must == target, find the most right == target, nums should be incremently sorted
	int search_fix_left_border(vector<int>& nums, int target, int startloc, int endloc)
	{
		int left = startloc;
		int right = endloc;
		int res = 0;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] > target) right = mid - 1;
			else
			{
				if (mid == right)
				{
					res = right;
					break;
				}
				else if (nums[mid + 1] != target)
				{
					res = mid;
					break;
				}
				else left = mid + 1;
			}
		}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 1,2,3,3,3,3,4,5,9 };
	vector<int> res = s->searchRange(nums, 3);
}