#include "public.h"

//simple problem, ��ѧ, 4ms, 92.65%
//�����ж�5������(��Ϊ2һ����5��)
//��ͣ�س���5��Сֵ

class Solution {
public:
	int trailingZeroes(int n) {
		//ʶ��5/5ƽ��/5���η�������
		//��ֻ��Ҫ�����n/5 ; n/25....��ֵ�Ϳ�

		int iter_five = 5;
		int res = 0;
		while (n >= iter_five)
		{
			res += n / iter_five;
			if (iter_five > 1000000000) break;  //��ֹ���
			iter_five *= 5;
		}
		return res;
	}
};
