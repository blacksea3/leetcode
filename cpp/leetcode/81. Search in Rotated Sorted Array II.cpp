#include "public.h"

//12ms, 88.85%

//use Binary search, pay attention to the sorted judge

class Solution {
public:
	//here nums[startloc, endloc] may be sorted or not
	int iter_search_81(vector<int>& nums, int target, int startloc, int endloc)
	{
		//binary cut
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
			//cut into [startloc,mid],  [mid+1,endloc]

			//one spqcial input: although nums[startloc] <= nums[mid], itisn't a sorted array
			//for exm, 1 3 1 1 1
			//This time: 这个时候应当首先判断首位是否相同,然后往中间搜,直接遍历搜索吧
			
			bool is_lefthalf_sorted = true;

			if (nums[startloc] != nums[endloc])
			{
				is_lefthalf_sorted = (nums[startloc] <= nums[mid]);
				//if [0,mid] isn't incremently sorted, then [mid+1,endloc] must be incremently sorted
			}
			else
			{
				//find whether [startloc,mid] is incremently sorted
				if (nums[startloc] < nums[mid]) is_lefthalf_sorted = true;
				else
				{
					//if left half only one item, then is_lefthalf_sorted will be default true
					for (int i = (startloc + 1); i <= mid; i++)
						if (nums[i] != nums[startloc]) is_lefthalf_sorted = false;
				}
			}
			if (is_lefthalf_sorted)
			{
				if (nums[startloc] <= target)
					if (target <= nums[mid])
						return binary_search_81(nums, target, startloc, mid);
					else //target may in the latter half
					{
						//the latter half may not be incremently sorted
						bool is_righthalf_sorted = true;  //
						if (nums[mid + 1] < nums[endloc]) is_righthalf_sorted = true;
						else
						{
							//if right half only one item, then is_righthalf_sorted will be default true
							for (int i = (mid + 2); i <= endloc; i++)
								if (nums[i] != nums[mid + 1]) is_righthalf_sorted = false;
						}

						if (is_righthalf_sorted)     //[mid+1,endloc] is incremently sorted
							return binary_search_81(nums, target, mid + 1, endloc);
						else
							return iter_search_81(nums, target, mid + 1, endloc);
					}
				else
					return iter_search_81(nums, target, mid + 1, endloc);
			}
			else
			{
				if (nums[mid + 1] <= target)
					if (target <= nums[endloc])
						return binary_search_81(nums, target, mid + 1, endloc);
					else
						return iter_search_81(nums, target, startloc, mid);
				else
					return iter_search_81(nums, target, startloc, mid);
			}

		}
	}

	int binary_search_81(vector<int>& nums, int target, int startloc, int endloc)
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

	bool search(vector<int>& nums, int target)
	{
		int nsize = nums.size();
		if (nsize == 0) return false;
		if (nsize == 1)
		{
			if (nums[0] == target) return true;
			else return false;
		}

		//next are nsize >= 2 condition, recursively
		if (iter_search_81(nums, target, 0, nsize - 1) == -1)
			return false;
		else return true;
	}
};