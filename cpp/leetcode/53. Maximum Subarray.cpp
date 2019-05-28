#include "public.h"

//12ms, 95.28%

//brute force
//I think there is no need to use divide and conquer :), the brute force is ok for easy problem :)

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int res = nums[0];
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (sum > 0) sum += nums[i];
			else sum = nums[i];
			res = (res < sum) ? sum : res;
		}
		return res;
	}
};
