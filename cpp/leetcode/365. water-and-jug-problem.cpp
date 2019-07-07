#include "public.h"

//4ms, 86.55%
//z=ax+by && z <= (x+y)
//a��b�����и���, ����ʾ�����Ǹ�Ͱ, ����ʾ����ĳ��Ͱ
//��1 1�ⲻ���ܶ���������

class Solution {
public:
	bool canMeasureWater(int x, int y, int z) {
		if (z == 0) {
			return true;
		}
		if (x + y < z) {
			return false;
		}
		if (x < y) {  //ʹ�ó�ʼ����: x����y, �Խ��н�������շת�����
			swap(x, y);
		}
		if (y > 0) {
			int r = x % y;
			while (r > 0) {
				x = y;
				y = r;
				r = x % y;
			}
			return z % y == 0;
		}
		return z % x == 0;
	}
};
