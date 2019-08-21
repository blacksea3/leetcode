#include "public.h"

//8ms, 19.46%
//模拟

class Solution {
public:
	bool hasAlternatingBits(int n) {
		bool flag = n % 2; //true: 上一个是1, false上一个是0
		n /= 2;

		while (n > 0)
		{
			if (flag)
			{
				if (n % 2)
					return false;
				else
					flag = false;
			}
			else
			{
				if (n % 2)
					flag = true;
				else
					return false;
			}
			n /= 2;
		}
		return true;
	}
};
