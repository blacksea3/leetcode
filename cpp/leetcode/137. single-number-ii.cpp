#include "public.h"

//12ms, 86.40%
//复杂的位运算, 数字电路

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//应该想出一个操作:使得连续三次操作后为0

		//对于两个1bit数:(a,b)    0  0  ->   0  1 ->  1  0  -> 0   0
		//input 1:

		//b = (b^i) & ~a = 0^1 & 1 = 1   //单个数字取b
		//a = (a^i) & ~b = 0^1 & 0 = 0

		//b = (b^i) & ~a = 1^1 & 1 = 0
		//a = (a^i) & ~b = 0^1 & 1 = 1   //两个数字取a

		//b = (b^i) & ~a = 0^1 & 0 = 0
		//a = (a^i) & ~b = 1^1 & 1 = 0

		//input 0

		//b = (b^i) & ~a = 0^0 & 1 = 0
		//a = (a^i) & ~b = 0^0 & 1 = 0
		//连着三遍

		int a = 0;
		int b = 0;
		for (auto& num : nums)
		{
			b = (b ^ num) & ~a;
			a = (a ^ num) & ~b;
		}
		return b;
	}
};
