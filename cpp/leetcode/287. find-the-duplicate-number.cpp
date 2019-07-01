#include "public.h"

//16ms, 83.13%
//等效成链表: 下标->值
//一定存在环, 找出起始交点

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int fast = nums[nums[0]];
		int slow = nums[0];

		while (fast != slow)
		{
			fast = nums[nums[fast]];
			slow = nums[slow];
		}

		//从头开始
		slow = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}

		return fast;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 1,3,4,2,2 };
	cout << s->findDuplicate(nums);
	return 0;
}
*/
