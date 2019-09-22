#include "public.h"

//12ms, 97.73%
//位运算, 使用异或

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//异或
		int i = 0;
		for (auto& num : nums)
			i ^= num;
		return i;
	}
};
