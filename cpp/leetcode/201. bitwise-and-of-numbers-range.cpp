#include "public.h"

//12ms, 94.22%
//�൱����m��n�Ĵ����λ��ʼ��������ͬλ

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int res = 0;
		int k = 0x40000000; // �Ǹ���������������
		while (k > 0 && (m & k) == (n & k))
		{
			res |= k & m;
			k >>= 1;
		}
		return res;
	}
};
