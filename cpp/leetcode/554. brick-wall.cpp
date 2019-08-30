#include "public.h"

//60ms, 90.31%
//暴力: 统计每一行的前n项和, 记录至unordered_map, 统计前n项和出现次数最多的
//考虑到总砖块数量<=20000, 这样可行

class Solution {
public:
	int leastBricks(vector<vector<int>>& wall) {
		unordered_map<int, int> count;

		for (auto& iter_wall : wall)
		{
			int preSum = 0;
			for (int index = 0; index < iter_wall.size() - 1; ++index)
			{
				preSum += iter_wall[index];
				count[preSum]++;
			}
		}

		int maxCount = 0;

		for (auto& iter_count : count)
		{
			if (iter_count.second > maxCount)
			{
				maxCount = iter_count.second;
			}
		}
		return wall.size() - maxCount;
	}
};
