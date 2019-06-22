#include "public.h"

//20ms, 98.82%
//三次反转操作

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.size() == 0) return;  //dump

		//先得知有效的移动次数
		k = k % nums.size();
		if (k == 0) return;  //不需要旋转

		//用评论的方法,时间复杂度O(n)
		//反转前半部分,后半部分,全部,  复杂度可以认为是O(2*n) = O(n)

		reverse(nums.begin(), nums.begin() + nums.size() - k);
		reverse(nums.begin() + nums.size() - k, nums.end());
		reverse(nums.begin(), nums.end());

	}
};
