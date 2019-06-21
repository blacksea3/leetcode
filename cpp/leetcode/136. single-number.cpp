#include "public.h"

//位运算, 使用异或, 20ms, 84.10%

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//异或

		int i = 0;
		for (auto num : nums)
			i ^= num;
		return i;
	}
};