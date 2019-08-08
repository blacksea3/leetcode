#include "public.h"

//80ms, 6.52%
//找到出现的最小的数字, 同时它不能同时存在于某一个fronts和backs

class Solution {
public:
	int flipgame(vector<int>& fronts, vector<int>& backs) {
		set<int> bad;
		set<int> all;

		for (int i = 0; i < fronts.size(); ++i)
		{
			if (fronts[i] == backs[i]) bad.insert(fronts[i]);
			all.insert(fronts[i]);
			all.insert(backs[i]);
		}

		for (auto& a : all)
		{
			if (bad.find(a) == bad.end()) return a;
		}

		return 0;
	}
};
