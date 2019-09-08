#include "public.h"

//0ms, 100%
//判断:存在这样的序列: 有两个点的线的中点和另外两个点的线的中点重合, 并且两条线呈90°关系, 并且两条线等长
//这样的序列仅需判断三次:
//注意选取的线长度不能都是0!

class Solution {
public:
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		int mid1x, mid1y, mid2x, mid2y, len1_square, len2_square;
		//第一次判断, 1-2; 3-4
		mid1x = (p1[0] + p2[0]) / 2;
		mid1y = (p1[1] + p2[1]) / 2;
		mid2x = (p3[0] + p4[0]) / 2;
		mid2y = (p3[1] + p4[1]) / 2;

		if (mid1x == mid2x && mid1y == mid2y)
		{
			len1_square = (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]);
			len2_square = (p3[0] - p4[0])*(p3[0] - p4[0]) + (p3[1] - p4[1])*(p3[1] - p4[1]);
			if (len1_square == len2_square && len1_square != 0)
			{
				if (((p1[0] - p2[0])*(p3[0] - p4[0]) +
					(p1[1] - p2[1])*(p3[1] - p4[1])) == 0)
					return true;
			}
		}

		//第二次判断, 1-3; 2-4
		mid1x = (p1[0] + p3[0]) / 2;
		mid1y = (p1[1] + p3[1]) / 2;
		mid2x = (p2[0] + p4[0]) / 2;
		mid2y = (p2[1] + p4[1]) / 2;

		if (mid1x == mid2x && mid1y == mid2y)
		{
			len1_square = (p1[0] - p3[0])*(p1[0] - p3[0]) + (p1[1] - p3[1])*(p1[1] - p3[1]);
			len2_square = (p2[0] - p4[0])*(p2[0] - p4[0]) + (p2[1] - p4[1])*(p2[1] - p4[1]);
			if (len1_square == len2_square && len1_square != 0)
			{
				if (((p1[0] - p3[0])*(p2[0] - p4[0]) +
					(p1[1] - p3[1])*(p2[1] - p4[1])) == 0)
					return true;
			}
		}

		//第二次判断, 1-4; 2-3
		mid1x = (p1[0] + p4[0]) / 2;
		mid1y = (p1[1] + p4[1]) / 2;
		mid2x = (p2[0] + p3[0]) / 2;
		mid2y = (p2[1] + p3[1]) / 2;

		if (mid1x == mid2x && mid1y == mid2y)
		{
			len1_square = (p1[0] - p4[0])*(p1[0] - p4[0]) + (p1[1] - p4[1])*(p1[1] - p4[1]);
			len2_square = (p2[0] - p3[0])*(p2[0] - p3[0]) + (p2[1] - p3[1])*(p2[1] - p3[1]);
			if (len1_square == len2_square && len1_square != 0)
			{
				if (((p1[0] - p4[0])*(p2[0] - p3[0]) +
					(p1[1] - p4[1])*(p2[1] - p3[1])) == 0)
					return true;
			}
		}

		return false;
	}
};
