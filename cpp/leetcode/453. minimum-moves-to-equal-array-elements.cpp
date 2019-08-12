#include "public.h"

//40ms, 99.51%
//每次移动相当于给1个元素减1
//找到最小值, 别的都减到那个值就行

class Solution {
public:
	int minMoves(vector<int>& nums) {
		int res = 0;
		int minval = *min_element(nums.begin(), nums.end());

		for (auto& num : nums) res += num - minval;
		return res;
	}
};
