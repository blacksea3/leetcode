#include "public.h"

//4ms, 88.35%
//����S������J���Ҿ���

class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int res = 0;
		for (auto& iis : S) if (J.find(iis) != J.npos) res++;
		return res;
	}
};

