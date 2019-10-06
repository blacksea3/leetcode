#include "public.h"

//568ms, 90.39%
//暴力O(n^2)
//定中间的点, 然后用unordered_map记录其他点和它距离的平方的次数
//注: 提交结果200ms左右似乎有vector记录次数的方法, 时间效率更高, 但代码复杂度很大

class Solution {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		int res = 0;

		for (auto& middle : points)
		{
			unordered_map<int, int> distance_squares;
			for (auto& side : points)
			{
				distance_squares[(middle[0] - side[0])*(middle[0] - side[0]) + (middle[1] - side[1])*(middle[1] - side[1])]++;
			}
			for (auto& distance_square : distance_squares)
				res += (distance_square.second - 1)*distance_square.second;
		}
		return res;
	}
};
