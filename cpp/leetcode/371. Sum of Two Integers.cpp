#include "public.h"

//0ms, 100%

//bit caculate  //assume that the result will not overflow

class Solution {
public:
	int getSum(int a, int b) {
		while (b)
		{
			// WHY THE FUCK OVERFLOW WILL OCCUR IN LEETCODE???
			auto c = ((unsigned int)a&b) << 1;
			a = a ^ b;
			b = c;  //auto cut 64bit off to 32bit 
		}
		return a;
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->getSum(4, 7);
	return 0;
}
