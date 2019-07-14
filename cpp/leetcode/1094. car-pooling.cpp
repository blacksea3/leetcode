#include "public.h"

//16ms, 81.18%
//线性扫描: 把上下车信息记录在一个vector<int> vabs中表示当前位置相对前一个位置的人数增加量

class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		vector<int> vabs(1001, 0);

		for (int i = 0; i < trips.size(); ++i)
		{
			vabs[trips[i][1]] += trips[i][0];
			vabs[trips[i][2]] -= trips[i][0];
		}

		int pre = 0;
		for (int i = 0; i < 1000; ++i)
		{
			pre += vabs[i];
			if (pre > capacity) return false;
		}
		return true;
	}
};
