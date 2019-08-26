#include "public.h"

//12ms, 70.97%
//

class Solution {
public:
	bool xorGame(vector<int>& nums) {
		//计算所有异或, 如果就是0, 那么小红获胜, 否则当nums是偶数个时小红获胜
		int xo = 0;
		for (auto& n : nums) xo ^= n;
		if (xo == 0 || nums.size() % 2 == 0) return true;
		else return false;
	}
};
