#include "public.h"

//
//±©Á¦, Í³¼Ædelta

class Solution {
public:
	int missingNumber(vector<int>& arr) {
		int delta1 = 0;
		int delta2 = 0;

		for (int index = 1; index < arr.size(); ++index)
		{
			if (delta1 == 0)
			{
				delta1 = arr[index] - arr[index - 1];
			}
			else if (delta1 == (arr[index] - arr[index - 1]))
			{
				continue;
			}
			else if (delta2 == 0)
			{
				delta2 = arr[index] - arr[index - 1];
			}
			else
			{
				continue;
			}
		}

		int targetdel;
		if (delta1 == 2 * delta2) targetdel = delta2;
		else targetdel = delta1;

		for (int index = 1; index < arr.size(); ++index)
		{
			if ((arr[index] - arr[index - 1]) != targetdel)
			{
				return arr[index - 1] + targetdel;
			}
		}
		return arr[0];
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> arr = { 5,7,11,13 };
	cout << s->missingNumber(arr);
	return 0;
}
*/
