#include "public.h"

//4ms, 88.76%
//±©Á¦

class Solution {
public:
	vector<int> distributeCandies(int candies, int num_people) {
		vector<int> res(num_people, 0);
		int times = 0;

		while (candies > 0)
		{
			if (candies >= (times + 1))
			{
				res[times%num_people] += (times + 1);
				candies -= (times + 1);
			}
			else
			{
				res[times%num_people] += candies;
				break;
			}
			times++;
		}
		return res;
	}
};
