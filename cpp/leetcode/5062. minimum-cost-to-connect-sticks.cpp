#include "public.h"

//
//维护一个优先队列

class Solution {
public:
	int connectSticks(vector<int>& sticks) {
		multiset<int> s(sticks.begin(), sticks.end());

		int res = 0;

		while (s.size() >= 2)
		{
			int first = *s.begin();
			s.erase(s.begin());
			int second = *s.begin();
			s.erase(s.begin());
			res += first + second;
			s.insert(first + second);
		}

		return res;
	}
};