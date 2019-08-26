#include "public.h"

//8ms, 77.42%

class Solution {
public:
	bool isBoomerang(vector<vector<int>>& points) {
		//��б��

		int x1, x2, x3, y1, y2, y3;
		x1 = points[0][0];
		x2 = points[1][0];
		x3 = points[2][0];
		y1 = points[0][1];
		y2 = points[1][1];
		y3 = points[2][1];

		//��ȥ���ظ���
		if ((x1 == x2) && (y1 == y2)) return false;
		if ((x1 == x3) && (y1 == y3)) return false;
		if ((x2 == x3) && (y2 == y3)) return false;

		//Ȼ��ȥ����ͬx�����
		if ((x1 == x2) && (x1 == x3)) return false;
		if ((x1 == x2) && (x1 != x3)) return true;
		if ((x1 == x3) && (x2 != x3)) return true;
		if ((x2 == x3) && (x1 != x2)) return true;

		//������:   (y2-y1)/(x2-x1) = (y3-y1)/(x3-x1)
		//�ĳɳ˷�

		if ((y2 - y1)*(x3 - x1) == (x2 - x1)*(y3 - y1)) return false;
		else return true;



	}
};

