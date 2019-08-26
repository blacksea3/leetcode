#include "public.h"

//4ms, 84.68%
//Ä£Äâ

class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		multiset<int> ml;
		for (auto stone : stones)
		{
			ml.insert(stone);
		}
		while (ml.size() >= 2)
		{
			int s1 = *ml.rbegin();
			ml.erase(ml.find(s1));
			int s2 = *(ml.rbegin());
			ml.erase(ml.find(s2));
			if (s1 != s2)
			{
				ml.insert(s1 - s2);
			}
		}
		return (ml.size() == 1) ? *ml.begin() : 0;
	}
};
