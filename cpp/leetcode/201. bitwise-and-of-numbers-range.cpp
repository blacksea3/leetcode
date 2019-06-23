#include "public.h"

//位运算, 8ms, 99.33%

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		//确定最高位
		int loc = 31;
		m <<= 1;
		n <<= 1;
		while (true)
		{
			if (m & 0x80000000)
				if (n & 0x80000000)
				{
					break;
				}
				else
					return 0;
			else if (n & 0x80000000)
				return 0;
			else
			{
				loc--;
				m <<= 1;
				n <<= 1;
			}
			if (loc == 0) return 0;
		}

		//此时的loc为公共的最高位，最低位的loc是1，且当前的m与n最高位已经移动到了loc处(位移动)

		int res = 0;

		while (true)
		{
			if (m & 0x80000000)
				if (n & 0x80000000)
				{
					m &= 0x7fffffff;
					n &= 0x7fffffff;
					res <<= 1;
					res |= 1;
				}
				else
					break;
			else if (n & 0x80000000)
				break;
			else
			{
				res <<= 1;
			}
			loc--;
			m <<= 1;
			n <<= 1;
			if (loc == 0) return res;
		}
		res <<= loc;

		return res;


	}
};
