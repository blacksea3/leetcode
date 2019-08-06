#include "public.h"

//4ms, 74.16%
//只有当两者的横坐标交叉且纵坐标交叉才构成重叠

class Solution {
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		int x11 = rec1[0];
		int y11 = rec1[1];
		int x12 = rec1[2];
		int y12 = rec1[3];
		int x21 = rec2[0];
		int y21 = rec2[1];
		int x22 = rec2[2];
		int y22 = rec2[3];

		if (
			((x21 > x11 && x21 < x12) || (x11 > x21 && x11 < x22)) &&
			((y21 > y11 && y21 < y12) || (y11 > y21 && y11 < y22))
			)
			return true;
		else return false;
	}
};

