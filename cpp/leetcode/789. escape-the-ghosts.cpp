#include "public.h"

//12ms, 65.28%
//判断距离: 只要阻碍者的最短的一个距离<=我的距离那么false, 否则true, 用曼哈顿距离

class Solution {
public:
	bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
		int minghosts_dis = INT_MAX;

		for (auto& g : ghosts)
		{
			minghosts_dis = min(minghosts_dis, abs(g[0] - target[0]) + abs(g[1] - target[1]));
		}

		int my_dis = abs(target[0]) + abs(target[1]);

		return my_dis < minghosts_dis;
	}
};
