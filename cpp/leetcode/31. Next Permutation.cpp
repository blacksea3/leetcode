#include "public.h"

//8ms, 99.75%

//consider these conditions:
// first: all decremently sorted, the next will be the smallest(incremently sorted)
// second: partly reverse sort: for exm: 942  3670  then swap 3 and 2 because 3 is is the smallest and 
//    bigger than 2 among these numbers after 2:(3,6,7,0), then for 2670, sort them incremently

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		bool is_all_reverse_sort = true;
		int keyloc = -1;
		int nsize = nums.size();
		if (nsize <= 1) return;
		else
		{
			int old_num = nums[nsize - 1];
			for (int i = nsize - 2; i >= 0; i--)
			{
				if (nums[i] < old_num)
				{
					is_all_reverse_sort = false;
					keyloc = i;
					break;
				}
				old_num = nums[i];
			}

			if (is_all_reverse_sort)  //all decremently sorted
				sort(nums.begin(), nums.end());
			else
			{
				int j;
				//find the smallest and bigger than nums[keyloc]
				for (j = keyloc + 2; j < nsize; j++)
					if (nums[j] <= nums[keyloc]) break;
				//swap
				int temp = nums[keyloc];
				nums[keyloc] = nums[j - 1];
				nums[j - 1] = temp;
				//sort incremently
				sort(nums.begin() + keyloc + 1, nums.end());
			}
		}
	}
};
