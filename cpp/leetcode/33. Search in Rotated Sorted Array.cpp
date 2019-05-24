#include "public.h"

//8ms, 96.01%

//binary search (or say: divide and conquer)

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int nsize = nums.size();
		if (nsize == 0) return -1;
		if (nsize == 1)
		{
			if (nums[0] == target) return 0;
			else return -1;
		}
		return recu_search(nums, target, 0, nsize - 1);
	}

	//[startloc, endloc] are nums locs, should be vaild
	int recu_search(vector<int>& nums, int target, int startloc, int endloc)
	{
		//binary 
		int nsize = endloc - startloc;
		if (nsize < 0) return -1;
		if (nsize == 0)
		{
			if (nums[startloc] == target) return startloc;
			else return -1;
		}
		else
		{
			int mid = (startloc + endloc) / 2;   //here mid must < endloc
			//the nums then be divided into [startloc,mid] and [mid+1,endloc]
			if (nums[startloc] <= nums[mid])  //[0,mid] incremently sorted
			{
				if (nums[startloc] <= target)
					if (target <= nums[mid])  //target may be in [0,mid]
						return binary_search(nums, target, startloc, endloc);
					else
						if (nums[mid + 1] <= nums[endloc]) //[mid+1,endloc]incremently sorted, target may be in them
							return binary_search(nums, target, mid + 1, endloc);
						else
							return recu_search(nums, target, mid + 1, endloc);  //recu again
				else
					return recu_search(nums, target, mid + 1, endloc);
			}
			else //if [0,mid]not incremently sorted, then[mid+1,endloc]must be incremently sorted
			{
				if (nums[mid + 1] <= target)
					if (target <= nums[endloc]) //target may be in[mid+1,endloc]
						return binary_search(nums, target, mid + 1, endloc);
					else  //recu again
						return recu_search(nums, target, startloc, mid);
				else  //recu again
					return recu_search(nums, target, startloc, mid);
			}
		}
	}

	//binary search, nums should be incremently sorted, startloc and endloc should be valid
	int binary_search(vector<int>& nums, int target, int startloc, int endloc)
	{
		int left = startloc;
		int right = endloc;
		if (right < left) return -1;
		if (right == left)
		{
			if (nums[left] == target) return left;
			else return -1;
		}
		else
		{
			while (left <= right)
			{
				int mid = (left + right) / 2;
				if (nums[mid] < target) left = mid + 1;
				else if (nums[mid] > target) right = mid - 1;
				else return mid;
			}
		}
		return -1;
	}
};