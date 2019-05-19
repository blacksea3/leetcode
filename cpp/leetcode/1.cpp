#include "public.h"

//8ms 99.90%

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		//”√map«ÛΩ‚
		unordered_map<int, int> mdict;
		int loc = 0;
		for (auto num : nums)
		{
			if (mdict.find(target - num) == mdict.end())
				mdict[num] = loc;
			else
				return vector<int> {mdict[target - num], loc};
			loc++;
		}
		return vector<int> {-1, -1};
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 2,7,11,15 };
	vector<int> res = s->twoSum(nums, 9);
	int i = 1;
}
