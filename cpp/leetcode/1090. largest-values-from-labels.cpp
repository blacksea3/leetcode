#include "public.h"

//84ms, 26.97%
//贪心: 给数据分组, 然后每组挑use_limit个最大值出来
//对所有的最大值, 再挑num_wanted个最大值出来

class Solution {
public:
	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
		unordered_map<int, vector<int>> um;

		for (int i = 0; i < values.size(); ++i)
		{
			um[labels[i]].push_back(values[i]);
		}

		vector<int> maybe = {};

		for (unordered_map<int, vector<int>>::iterator iter = um.begin(); iter != um.end(); ++iter)
		{
			vector<int> temp = iter->second;
			sort(temp.begin(), temp.end(), greater<int>());
			for (int i = 0; i < min((int)temp.size(), use_limit); ++i)
			{
				maybe.push_back(temp[i]);
			}
		}

		sort(maybe.begin(), maybe.end(), greater<int>());

		int res = 0;

		for (int i = 0; i < min((int)maybe.size(), num_wanted); ++i)
			res += maybe[i];

		return res;
	}
};
