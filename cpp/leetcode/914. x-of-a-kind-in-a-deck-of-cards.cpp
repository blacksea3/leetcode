#include "public.h"

//40ms, 12.79%
//记录所有元素的数量
//然后求最大公约数, >=2则OJBK

class Solution {
public:
	bool hasGroupsSizeX(vector<int>& deck) {
		unordered_map<int, int> um;
		for (auto& d : deck) um[d]++;
		vector<int> v;
		for (auto& u : um) v.push_back(u.second);

		//暴力
		for (int i = 2; i <= *max_element(v.begin(), v.end()); ++i)
		{
			bool allpass = true;
			for (int loc = 0; loc < v.size(); ++loc)
			{
				if (v[loc] % i)
				{
					allpass = false;
					break;
				}
			}
			if (allpass) return true;
		}
		return false;
	}
};
