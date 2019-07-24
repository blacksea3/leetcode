#include "public.h"

//4ms, 79.46%
//反过来
//Y除以2或者加一, 多个步骤后到X
//Y比X大则能除就除, 不能除再加
//Y比X小直接加

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
