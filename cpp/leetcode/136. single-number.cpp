#include "public.h"

//λ����, ʹ�����, 20ms, 84.10%

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//���

		int i = 0;
		for (auto num : nums)
			i ^= num;
		return i;
	}
};