#include "public.h"

//12ms, 86.40%
//���ӵ�λ����, ���ֵ�·

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//Ӧ�����һ������:ʹ���������β�����Ϊ0

		//��������1bit��:(a,b)    0  0  ->   0  1 ->  1  0  -> 0   0
		//input 1:

		//b = (b^i) & ~a = 0^1 & 1 = 1   //��������ȡb
		//a = (a^i) & ~b = 0^1 & 0 = 0

		//b = (b^i) & ~a = 1^1 & 1 = 0
		//a = (a^i) & ~b = 0^1 & 1 = 1   //��������ȡa

		//b = (b^i) & ~a = 0^1 & 0 = 0
		//a = (a^i) & ~b = 1^1 & 1 = 0

		//input 0

		//b = (b^i) & ~a = 0^0 & 1 = 0
		//a = (a^i) & ~b = 0^0 & 1 = 0
		//��������

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
