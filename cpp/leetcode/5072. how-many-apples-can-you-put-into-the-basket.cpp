#include "public.h"

//
//尽量装小的

class Solution {
public:
	int maxNumberOfApples(vector<int>& arr) {
		sort(arr.begin(), arr.end());

		int res = 0;
		int pre = 0;
		for (int index = 0; index < arr.size(); ++index)
		{
			pre += arr[index];
			if (pre < 5000)
			{
				res++;
			}
			else
			{
				break;
			}
		}
		return res;
	}
};
