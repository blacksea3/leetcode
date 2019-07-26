#include "public.h"

//
//这相当于用1,x,x*x,x*x*x...的加减生成target, 且加减总量最少
//貌似是个数学题

//搞清楚x的多少次方可以生成比target大的数字, 而且这个次方数还是最小的

class Solution {
public:
	int leastOpsExpressTarget(int x, int target) {
		vector<int> r;

		while (target > 0)
		{
			r.push_back(target%x);
			target /= x;
		}

		int res = 0;

		for (int i = 1; i < r.size(); ++i)
		{
			if (r[i] <= x / 2) res += 2* r[i];
			else res += 2*(x - r[i]);
		}

		if (r[0] * 2 > (1 + x - r[0])) res += 1 + x - r[0];
		else res += r[0] * 2;
		return res - 1;
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->leastOpsExpressTarget(3, 19);
	return 0;
}
