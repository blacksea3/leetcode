#include "public.h"

//4ms, 79.46%
//������
//Y����2���߼�һ, ��������X
//Y��X�����ܳ��ͳ�, ���ܳ��ټ�
//Y��XСֱ�Ӽ�

class Solution {
public:
	int brokenCalc(int X, int Y) {
		int res = 0;
		while (Y > X)
		{
			if (Y % 2 == 0) Y /= 2;
			else Y++;
			res++;
		}
		return res + (X - Y);
	}
};
