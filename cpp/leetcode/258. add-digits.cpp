#include "public.h"

//8ms, 80.94%
//O(1)ʱ�临�Ӷ�, ��ô������ѧ��

class Solution {
public:
	int addDigits(int num) {
		return ((num - 1) % 9) + 1;
	}
};
