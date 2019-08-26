#include "public.h"

//160ms, 60.17%
//扫描list1和list2, 把索引与出现次数放入unordered_map<string, pair<int, int>>
//也就是说, 值的pair<int, int>第一个放索引和第二个放出现次数
//然后统计unordered_map即可

class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		unordered_map<string, pair<int, int>> count;

		for (int i = 0; i < list1.size(); ++i)
		{
			count[list1[i]] = pair<int, int>{ i, 1 };
		}

		for (int i = 0; i < list2.size(); ++i)
		{
			if (count.find(list2[i]) != count.end())
			{
				count[list2[i]].second++;
				count[list2[i]].first += i;
			}
		}

		vector<string> res;
		int minsumloc = INT_MAX;

		for (auto& c : count)
		{
			if (c.second.second == 2)
			{
				if (minsumloc > c.second.first)
				{
					minsumloc = c.second.first;
					res.clear();
					res.push_back(c.first);
				}
				else if (minsumloc == c.second.first)
					res.push_back(c.first);
			}
		}
		return res;
	}
};
