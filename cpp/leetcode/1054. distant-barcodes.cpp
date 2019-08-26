#include "public.h"

//484ms, 32.73%
//按出现数量从大到小排序数字, 然后先放奇数位后放偶数位

class Solution {
public:
	vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		//计数
		unordered_map<int, int> um = {};
		for (auto barcode : barcodes) um[barcode]++;
		
		//按出现数量排序
		multimap<int, int, greater<int>> num_times;
		for (auto& u : um) num_times.insert(pair<int, int>{u.second, u.first});
		
		//放置
		vector<int> res(barcodes.size());
		
		int loc = 0;
		for (auto& nt : num_times)
		{
			for (int i = 0; i < nt.first; ++i)
			{
				if (loc >= res.size()) loc = 1;
				res[loc] = nt.second;
				loc += 2;
			}
		}
		return res;
	}
};
