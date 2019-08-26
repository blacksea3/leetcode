#include "public.h"

//116ms, 11.16%
//simple solution

class Solution {
public:
	void duplicateZeros(vector<int>& arr) {
		int abs_loc = 0;

		int preloc = 0;
		int maxloc = arr.size() - 1;

		int state = 0;   //0:wait 0,
		while (preloc <= maxloc)
		{
			if (arr[preloc] == 0)
			{
				arr.insert(arr.begin() + preloc, 0);
				preloc += 2;
			}
			else
			{
				preloc++;
			}
		}

		arr.resize(maxloc + 1);

	}
};
