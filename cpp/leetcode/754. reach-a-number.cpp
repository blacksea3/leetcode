#include "public.h"

//0ms, 100%
//不断累加1,2,3...直到sum>=target && (sum - target)是偶数, 此时说明将某些步骤反方向操作即可得到解答
//贪婪: 一旦差值是偶数, 一定存在一个已经走过的数字1-n中间的某种组合使得  sum减去两倍的它们的和  就变成了target

class Solution {
public:
	int reachNumber(int target) {
		int res = 0;
		int presum = 0;
		target = abs(target);

		while (target)
		{
			if (presum >= target && (presum - target) % 2 == 0) break;
			res++;
			presum += res;
		}
		return res;
	}
};
