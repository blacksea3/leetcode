#include "public.h"

//12ms, 100%
//找到中位数

class Solution {
public:
	int minMoves2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int nsize = nums.size();

		int res = 0;
		int midv = nums[nums.size() / 2];
		for (int i = 0; i < nums.size(); ++i)
			res += abs(nums[i] - midv);
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 1,2 };
	cout << s->minMoves2(nums);
	return 0;
}
*/
