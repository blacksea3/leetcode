#include "public.h"

//484ms, 32.73%
//�����������Ӵ�С��������, Ȼ���ȷ�����λ���ż��λ

class Solution {
public:
	vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		//����
		unordered_map<int, int> um = {};
		for (auto barcode : barcodes) um[barcode]++;
		
		//��������������
		multimap<int, int, greater<int>> num_times;
		for (auto& u : um) num_times.insert(pair<int, int>{u.second, u.first});
		
		//����
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
