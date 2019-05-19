#include "public.h"

//8ms 98.05%

//提前判断正负,按照正数处理
//对于特殊数INT_MIN单独处理

//溢出判断:当已经读了9位,那么先对前9位判断大小,然后对第10位判断大小

class Solution {
public:
	int reverse(int x) {
		if (x == INT_MIN) return 0;  //仅x==INT_MIN会x *= -1溢出

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




