#include "public.h"

//824ms, 52.35%
//半暴力
//定中间的点, 然后求其他点和它距离的平方, 统计频率
//用大数据long long, 防止溢出

class Solution {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		int res = 0;

		for (auto& middle : points)
		{
			unordered_map<long long, int> distance_squares;

			for (auto& side : points)
			{
				distance_squares[((long long)middle[0] - side[0])*((long long)middle[0] - side[0]) + ((long long)middle[1] - side[1])*((long long)middle[1] - side[1])]++;
			}

			for (auto& distance_square : distance_squares)
				res += (distance_square.second - 1)*distance_square.second;
		}

		return res;
	}
};

