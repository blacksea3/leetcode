#include "public.h"

//12ms, 98.69%

//special solution
//remember that: for all these locs can jump to, figure out the 
//  loc from which You can jump farest one more time: this means you'll have more choices
//  from this selected loc.

class Solution {
public:
	int jump(vector<int>& nums) {
		//traverse
		int nsize = nums.size();
		//special input
		if (nsize == 1) return 0;
		if (nsize == 2) return 1;
		if (nums[0] >= nsize - 1) return 1;

		int startloc = 0;
		int maxdistance = 0;
		int maxloc = 0;
		int times = 0;
		//assume that always can jump to the end
		int res = 0;
		while (true)
		{
			maxdistance = nums[startloc];
			maxdistance = 0;
			maxloc = 0;
			for (int i = 0; i < nums[startloc]; i++)
			{
				if ((i + nums[startloc + 1 + i]) > maxdistance)
				{
					maxdistance = i + nums[startloc + 1 + i];
					maxloc = startloc + 1 + i;
				}
			}
			times++;
			if ((maxloc + nums[maxloc]) >= nsize - 1)
			{
				res = (times + 1);
				break;
			}
			else startloc = maxloc;
		}
		return res;
	}
};
