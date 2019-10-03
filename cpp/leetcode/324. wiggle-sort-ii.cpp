#include "public.h"

//88ms, 91.70%
//O(nlogn), 理论时间复杂度可以O(n), 待优化
//先排序然后插入数据

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		vector<int> cpnums = nums;
		sort(cpnums.begin(), cpnums.end());
		int loc = 0;

		for (int i = (nums.size() - 1)/2*2; i >= 0; i -= 2)
			nums[i] = cpnums[loc++];

		for (int i = nums.size() / 2 * 2 - 1; i >= 1; i -= 2)
			nums[i] = cpnums[loc++];
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<int> nums = { 1,3,2,2,3,1 };
	vector<int> nums = { 4,5,5,6 };
	s->wiggleSort(nums);
	return 0;
}
*/
