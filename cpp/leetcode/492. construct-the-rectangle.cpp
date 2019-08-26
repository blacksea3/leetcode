#include "public.h"

//8ms, 55.79%
//����area����С��, ���ڵ���sqrt(area)������
//��ô�����area������, С�ڵ���sqrt(area)������

class Solution {
public:
	vector<int> constructRectangle(int area) {
		for (int i = (int)sqrt(area); i >= 2; --i)
			if (area%i == 0) return { area / i, i };

		return { area, 1 };
	}
};
