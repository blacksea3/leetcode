#include "public.h"

//232ms, 12.50%
//直接最重的和最轻的共用一艘船

class Solution {
public:
	int numRescueBoats(vector<int>& people, int limit) {
		deque<int> fuckdq(people.begin(), people.end());


		sort(fuckdq.begin(), fuckdq.end());
		int res = 0;
		while (!fuckdq.empty())
		{
			res++;
			if (fuckdq.size() == 1)
				fuckdq.pop_back();
			else if (fuckdq[0] + fuckdq[fuckdq.size() - 1] <= limit)
			{
				fuckdq.pop_back();
				fuckdq.pop_front();
			}
			else
				fuckdq.pop_back();
		}

		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> people = { 3,2,2,1 };
	cout << s->numRescueBoats(people, 3);
	return 0;
}
