#include "public.h"

//8ms 98.05%

//��ǰ�ж�����,������������
//����������INT_MIN��������

//����ж�:���Ѿ�����9λ,��ô�ȶ�ǰ9λ�жϴ�С,Ȼ��Ե�10λ�жϴ�С

class Solution {
public:
	int reverse(int x) {
		if (x == INT_MIN) return 0;  //��x==INT_MIN��x *= -1���

		bool positive;
		if (x > 0) positive = true;
		else
		{
			positive = false;
			x *= -1;
		}

		int res = 0;
		int loc = 0;
		while (x > 0)
		{
			int son = x % 10;
			x /= 10;
			if (res > 214748364) return 0;
			else if (res < 214748364)
			{
				res = res * 10 + son;
				loc++;
			}
			else
				if (positive) return (son > 7) ? 0 : (res * 10 + son);
				else return (son > 8) ? 0 : -1 * res * 10 - son;
		}
		return (positive) ? res : -1 * res;
	}
};




