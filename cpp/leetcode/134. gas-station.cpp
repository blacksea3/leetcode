#include "public.h"

//4ms, 99.82%
//贪婪
//开始行驶,如果某段路在结尾处油变成负的了,则重启起始点,记住之前负的值(可以与在之前的负的值叠加)
//这是因为如果起始点在那段中间的话,由于那段路没到结尾油是正的，则后面一块油负的更厉害，无需考虑。
//如果开到最后了,把多余的油与前面的总计负的值比较, 得出结论

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int pre_init = 0;
		int pre_nagative_res = 0;
		int startloc = 0;

		for (int i = 0; i < gas.size(); i++)
		{
			pre_init += gas[i] - cost[i];
			if (pre_init < 0)
			{
				pre_nagative_res += pre_init;
				pre_init = 0;
				startloc = (i + 1);
			}
		}

		return ((pre_init + pre_nagative_res) >= 0) ? startloc : -1;
	}
};
