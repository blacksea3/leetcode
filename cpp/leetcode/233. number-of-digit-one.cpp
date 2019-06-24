#include "public.h"

//4ms, 87.55%
//数学法, 实在无法做到答案如此简洁!

/*
作者：LeetCode
链接：https ://leetcode-cn.com/problems/two-sum/solution/shu-zi-1-de-ge-shu-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
	int countDigitOne(int n)
	{
		int countr = 0;
		for (long long i = 1; i <= n; i *= 10) {
			long long divider = i * 10;
			countr += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
		}
		return countr;
	}
};



