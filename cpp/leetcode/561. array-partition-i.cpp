#include "public.h"

//112ms, 35.87%
//����, Ȼ��ѡ���2���, ��4���...

class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int res = 0;
		sort(nums.begin(), nums.end());

		for (int loc = 0; loc < nums.size(); loc += 2)
			res += nums[loc];
		return res;
	}
};
