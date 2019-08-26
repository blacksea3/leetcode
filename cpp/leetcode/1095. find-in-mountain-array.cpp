#include "public.h"

//12ms, 58.16%
//多次利用二分查找

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
  public:
    int get(int index);
    int length();
};

class Solution {
private:
	// [start,end], end >= start
	int binarysearch(int target, MountainArray &mountainArr, int start, int end, bool upmode)
	{
		if (end < start) return -1;
		else
		{
			if (!upmode)
			{
				int mid = (end + start) / 2;
				int midres = mountainArr.get(mid);
				if (midres == target) return mid;
				else if (midres < target)
					return binarysearch(target, mountainArr, start, mid - 1, true);
				else
					return binarysearch(target, mountainArr, mid + 1, end, true);
			}
			else
			{
				int mid = (end + start) / 2;
				int midres = mountainArr.get(mid);
				if (midres == target) return mid;
				else if (midres > target)
					return binarysearch(target, mountainArr, start, mid - 1, true);
				else
					return binarysearch(target, mountainArr, mid + 1, end, true);
			}
		}
	}

	// [start,end]
	int recu_findInMountainArray(int target, MountainArray &mountainArr, int start, int end) {

		if ((end - start) == 0)
		{
			if (mountainArr.get(end) == target) return start;
			return -1;
		}
		else if ((end - start) == 1)
		{
			if (mountainArr.get(end) == target) return end;
			if (mountainArr.get(start) == target) return start;
			return -1;
		}
		else if ((end - start) == 2)
		{
			if (mountainArr.get(end) == target) return end;
			if (mountainArr.get(start) == target) return start;
			if (mountainArr.get(start + 1) == target) return start + 1;
			return -1;
		}
		else
		{
			int mid = (end + start) / 2;
			int left = mountainArr.get(mid);
			int right = mountainArr.get(mid + 1);
			int resloc_direct = -1;
			int resloc2_search = -1;

			if (left == target)
				resloc_direct = mid;
			else if (right == target)
				resloc_direct = mid + 1;

			if (left < right)
			{
				if (target < left)
				{
					int leftres = binarysearch(target, mountainArr, start, mid - 1, true);
					if (leftres != -1) resloc2_search = leftres;
				}
				int rightres = recu_findInMountainArray(target, mountainArr, mid + 2, end);
				if ((rightres != -1) && (resloc2_search == -1)) resloc2_search = rightres;
			}
			else
			{
				int leftres = recu_findInMountainArray(target, mountainArr, start, mid - 1);
				if (leftres != -1) resloc2_search = leftres;
				if (target < right)
				{
					int rightres = binarysearch(target, mountainArr, mid + 2, end, false);
					if ((rightres != -1) && (resloc2_search == -1)) resloc2_search = rightres;
				}
			}
			if ((resloc_direct == -1) && (resloc2_search == -1))
				return -1;
			else if (resloc_direct == -1)
				return resloc2_search;
			else if (resloc2_search == -1)
				return resloc_direct;
			else
				return min(resloc_direct, resloc2_search);
		}

	}

public:
	int findInMountainArray(int target, MountainArray &mountainArr) {
		int n = mountainArr.length();
		//binary search, BIG
		return recu_findInMountainArray(target, mountainArr, 0, n - 1);
	}
};
