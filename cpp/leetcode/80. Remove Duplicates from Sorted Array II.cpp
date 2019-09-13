#include "public.h"

//16ms, 92.43%
//模拟, 统计字符出现次数

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int nsize = nums.size();
		if (nsize == 0) return 0;

		int count = 1;
		int loc = 1;

		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] == nums[i - 1]) count++;
			else count = 1;
			if (count <= 2) nums[loc++] = nums[i];
		}

		return loc;
	}
};
