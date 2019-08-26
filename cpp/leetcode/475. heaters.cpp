#include "public.h"

//176ms, 6.10%
//排序房屋和加热器位置
//对每个房屋, 它可能和一个或两个加热器最挨着, 取距离近的
//在所有近距离中找出最大的

class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		int res = 0;
		//给非常遥远的地方放两个加热器: >> 10^9, <<0
		heaters.push_back(2000000000);
		heaters.push_back(-1000000000);

		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());

		//对每个房子, 都能发现它们被两个加热器夹着
		int heaterloc = 0;

		for (int houseloc = 0; houseloc < houses.size(); ++houseloc)
		{
			while (houses[houseloc] > heaters[heaterloc + 1]) heaterloc++;
			res = max(res, min(houses[houseloc] - heaters[heaterloc],
				heaters[heaterloc + 1] - houses[houseloc]));
		}
		return res;
	}
};
