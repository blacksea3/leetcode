#include "public.h"

//8ms, 83.12%
//类二分查找, 手动二分拆分

class Solution {
public:
	//here nums[startloc, endloc] may be sorted or not
	//注意闭区间
	bool quasi_binary_search(vector<int>& nums, int target, int startloc, int endloc)
	{
		//binary cut
		if (endloc < startloc) return false;
		else if (endloc == startloc)
		{
			if (nums[startloc] == target) return startloc;
			else return false;
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
						return m_binary_search(nums, target, startloc, mid);
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
							return m_binary_search(nums, target, mid + 1, endloc);
						else
							return quasi_binary_search(nums, target, mid + 1, endloc);
					}
				else
					return quasi_binary_search(nums, target, mid + 1, endloc);
			}
			else
			{
				if (nums[mid + 1] <= target)
					if (target <= nums[endloc])
						return m_binary_search(nums, target, mid + 1, endloc);
					else
						return quasi_binary_search(nums, target, startloc, mid);
				else
					return quasi_binary_search(nums, target, startloc, mid);
			}

		}
	}

	bool m_binary_search(vector<int>& nums, int target, int startloc, int endloc)
	{
		int left = startloc;
		int right = endloc;
		if (right < left) return -1;
		if (right == left)
		{
			if (nums[left] == target) return true;
			else return false;
		}
		else
		{
			while (left <= right)
			{
				int mid = (left + right) / 2;
				if (nums[mid] < target) left = mid + 1;
				else if (nums[mid] > target) right = mid - 1;
				else return true;
			}
		}
		return false;
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
		return quasi_binary_search(nums, target, 0, nsize - 1);
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 0,0 };
	auto res = s->search(nums, 1);
	return 0;
}
*/
