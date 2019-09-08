#include "public.h"

//
//ÆÓËØÄ£Äâ

class Solution {
public:
	int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
		int res_1 = 0;
		int sum = accumulate(distance.begin(), distance.end(), 0);

		for (int index = start; index < destination; ++index)
		{
			res_1 += distance[index];
		}

		return min(res_1, sum - res_1);
	}
};
