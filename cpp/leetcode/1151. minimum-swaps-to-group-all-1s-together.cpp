#include "public.h"

//
//“ª±È…®√Ë

class Solution {
public:
	int minSwaps(vector<int>& data) {
		int totalone = 0;
		for (auto& d : data) if (d == 1) totalone++;

		int preonenum = 0;
		//init
		for (int i = 0; i < totalone; ++i)
		{
			if (data[i] == 1) preonenum++;
		}

		int res = 0;
		res = totalone - preonenum;

		int preloc = totalone;

		while (preloc < data.size())
		{
			if (data[preloc - totalone] == 1) preonenum--;
			if (data[preloc] == 1) preonenum++;
			res = min(res, totalone - preonenum);
			preloc++;
		}

		return res;
	}
};
