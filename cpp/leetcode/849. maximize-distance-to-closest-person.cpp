#include "public.h"

//16ms, 83.50%
//Ò»ÂÖÉ¨Ãè

class Solution {
public:
	int maxDistToClosest(vector<int>& seats) {
		int res = -1;
		int old = -1;
		for (int i = 0; i < seats.size(); ++i)
		{
			if (seats[i] == 1)
			{
				if (old == -1)
				{
					res = i;
					old = i;
				}
				else
				{
					res = max((i - old) / 2, res);
					old = i;
				}
			}
			else continue;
		}
		res = max(((int)seats.size() - 1 - old), res);
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> seats = { 1,0,0,0 };
	cout << s->maxDistToClosest(seats);
	return 0;
}
*/
