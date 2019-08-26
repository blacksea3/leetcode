#include "public.h"

//80ms, 6.52%
//�ҵ����ֵ���С������, ͬʱ������ͬʱ������ĳһ��fronts��backs

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
