#include "public.h"

//
//求三点是否共线

class Solution {
private:
	bool isSameLine(vector<int> const& v1, vector<int> const& v2, vector<int> const& v3)
	{
		long long x1, x2, x3, y1, y2, y3;
		x1 = v1[0];
		y1 = v1[1];
		x2 = v2[0];
		y2 = v2[1];
		x3 = v3[0];
		y3 = v3[1];

		return ((y1 - y2)*(x1 - x3) - (y1 - y3)*(x1 - x2)) == 0;
	}


public:
	bool checkStraightLine(vector<vector<int>>& coordinates) {
		int cSize = coordinates.size();

		for (int index = 2; index < cSize; ++index)
		{
			if (!isSameLine(coordinates[index - 2], coordinates[index - 1], coordinates[index]))
				return false;
		}
		return true;
	}
};
