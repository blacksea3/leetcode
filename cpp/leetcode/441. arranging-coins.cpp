#include "public.h"

//12ms, 67.06%
//ģ��

class Solution {
public:
	int arrangeCoins(int n) {
		int line = 1;

		while (n >= line)
		{
			n -= line;
			line++;
		}
		return line;
	}
};

