#include "public.h"

//8ms, 19.46%
//ģ��

class Solution {
public:
	bool hasAlternatingBits(int n) {
		bool flag = n % 2; //true: ��һ����1, false��һ����0
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
