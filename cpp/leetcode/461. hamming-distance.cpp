#include "public.h"

//8ms, 29.73%
//�����, ��1�ĸ���

class Solution {
public:
	int hammingDistance(int x, int y) {
		int x_or = x ^ y;
		int res = 0;
		while (x_or > 0)
		{
			res += x_or % 2;
			x_or /= 2;
		}
		return res;
	}
};
