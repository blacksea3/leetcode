#include "public.h"

//4ms, 85.50%
//O(1)ʱ�临�Ӷ�, ��ô������ѧ��

class Solution {
public:
	int addDigits(int num) {
		return ((num - 1) % 9) + 1;
	}
};
