#include "public.h"

/*
//20ms, 98.51%
//原位操作
//理想情况是0, 1, 2..
//遍历, 如果特定数不在当前位置, 而且不等于nums.size(), 那么把这个数字与它的理想的位置上的数字交换,
//然后对当前位置再次判断

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++)
			while (!((nums[i] == n) || (nums[i] == i))) swap(nums[i], nums[nums[i]]);

		for (int i = 0; i < n; i++) if (nums[i] == n) return i;
		return n;
	}
};
*/

//24ms, 91.59%
//或者直接对0-n求和, 然后遍历减掉当前数字
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		return (nums.size())*(nums.size() + 1) / 2 - accumulate(nums.begin(), nums.end(), 0);
	}
};
