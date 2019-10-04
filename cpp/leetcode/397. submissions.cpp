#include "public.h"

//0ms, 100%
//数学, 迭代
//偶数直接除以2
//奇数: 如果结尾是01, 那么减1; 如果是11, 那么加1
//  奇数特殊情况: 如果是3, 那么如果加1则3->4->2->1
//      减1则3->2->1, 故直接次数+2

class Solution {
public:
	int integerReplacement(int n) {
		int res = 0;
		while (n > 3)
		{
			if (n % 2)
			{
				n >>= 1;
				if (n % 2) n++; //对应前述奇数结尾是11, 若n%2==0, 则结尾是01
				res += 2;
			}
			else
			{
				n >>= 1;
				res++;
			}
		}
		return res + n - 1;
	}
};
