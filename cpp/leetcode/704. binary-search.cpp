#include "public.h"

//64ms, 35.85%
//ʵ�ֶ�������

class Solution {
private:
	//��[start, end]������target
	int recu(const vector<int>& nums, int start, int end, int target)
	{
		if (start > end) return -1;
		else
		{
			int mid = (end - start) / 2 + start;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				return recu(nums, mid + 1, end, target);
			else
				return recu(nums, start, mid - 1, target);
		}
	}

public:
	int search(vector<int>& nums, int target) {
		return recu(nums, 0, nums.size() - 1, target);
	}
};
