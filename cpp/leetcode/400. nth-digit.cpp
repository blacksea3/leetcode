#include "public.h"

//8ms, 44.19%
//’“πÊ¬…

class Solution {
public:
	int findNthDigit(int n) {
		//9*1 90*2 900*3
		int cmp = 9;
		int mul = 1;
		int prenums = 0;
		while ((mul < 9) && (n > cmp*mul))
		{
			n -= cmp * mul;
			prenums += cmp;
			cmp *= 10;
			mul++;
		}
		int absloc = (n + 1) / mul;
		int detail = (n - 1) % mul;
		if (prenums == 0) absloc--;

		int realloc = (prenums + absloc);

		int res = (realloc / ((int)(pow(10, mul - detail - 1)))) % 10;
		return res;


	}
};
