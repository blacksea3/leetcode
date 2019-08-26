#include "public.h"

//136ms, 5.82%
//对timeSeries排序, 然后模拟

class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		sort(timeSeries.begin(), timeSeries.end());
		
		int res = 0;
		int leftTime = -1;
		int rightTime = -1;

		for (auto& timeSe : timeSeries)
		{
			if (leftTime == -1)
			{
				leftTime = timeSe;
				rightTime = leftTime + duration;
			}
			else if (rightTime <= timeSe)
			{
				res += (rightTime - leftTime);
				leftTime = timeSe;
				rightTime = leftTime + duration;
			}
			else
			{
				res += timeSe - leftTime;
				leftTime = timeSe;
				rightTime = leftTime + duration;
			}
		}
		res += (rightTime - leftTime);
		return res;
	}
};
