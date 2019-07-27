#include "public.h"

//12ms, 60.56%
//根据猜测, 总会出现这样的情况: 初始牢房占用情况->.....各种占用情况, 
//情况中会按某个周期重复, 找到那个周期就可以

class Solution {
private:
	unsigned char v2uc(const vector<int>& cells)
	{
		return cells[0] * 128 + cells[1] * 64 + cells[2] * 32 + cells[3] * 16 + cells[4] * 8 + cells[5] * 4 + cells[6] * 2 + cells[7];
	}

	vector<int> convert(const vector<int>& cells)
	{
		vector<int> res(8, 0);
		res[1] = (cells[0] == cells[2]) ? 1 : 0;
		res[2] = (cells[1] == cells[3]) ? 1 : 0;
		res[3] = (cells[2] == cells[4]) ? 1 : 0;
		res[4] = (cells[3] == cells[5]) ? 1 : 0;
		res[5] = (cells[4] == cells[6]) ? 1 : 0;
		res[6] = (cells[5] == cells[7]) ? 1 : 0;
		return res;
	}

public:
	vector<int> prisonAfterNDays(vector<int>& cells, int N) {
		unordered_map<unsigned char, int> um;
		unordered_map<int, vector<int>> r_um;

		int day = 0;
		vector<int> pre = cells;
		um[v2uc(cells)] = day;
		r_um[day] = cells;
		while (true)
		{
			pre = convert(pre);
			day++;

			if (day == N)
			{
				return pre;
			}
			else if (um.find(v2uc(pre)) != um.end())
			{
				//寻找周期
				int cycle = day - um[v2uc(pre)];
				return r_um[(N - um[v2uc(pre)]) % cycle + um[v2uc(pre)]];
			}
			else
			{
				um[v2uc(pre)] = day;
				r_um[day] = pre;
			}
		}
		return {}; //dump
	}
};
