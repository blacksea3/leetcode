#include "public.h"

//12ms, 70.97%
//

class Solution {
public:
	bool xorGame(vector<int>& nums) {
		//�����������, �������0, ��ôС���ʤ, ����nums��ż����ʱС���ʤ
		int xo = 0;
		for (auto& n : nums) xo ^= n;
		if (xo == 0 || nums.size() % 2 == 0) return true;
		else return false;
	}
};
