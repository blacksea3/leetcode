#include "public.h"

//12ms, 97.73%
//λ����, ʹ�����

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//���
		int i = 0;
		for (auto& num : nums)
			i ^= num;
		return i;
	}
};
