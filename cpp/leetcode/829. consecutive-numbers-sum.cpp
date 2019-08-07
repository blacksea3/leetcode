#include "public.h"

//8ms, 87.27%
//�ҹ���, ����ż, ֱ�ӿ�����

class Solution {
public:
	int consecutiveNumbersSum(int N) {
		int res = 0;

		//����
		for (int i = 1; ; i += 2)
		{
			if (N / i <= (i / 2)) break;
			if (N%i == 0) res++;
		}

		//ż��
		for (int i = 2; ; i += 2)
		{
			if (N / i < (i / 2)) break;
			if (N%i == (i / 2)) res++;
		}
		return res;
	}
};
