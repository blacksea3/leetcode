#include "public.h"

//0ms, 100%
//��ѧ
//�����ж�5������(��Ϊ2һ����5��)
//  ���������Ϊʶ��5 / 5ƽ�� / 5���η�������

class Solution {
public:
	int trailingZeroes(int n) {
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
