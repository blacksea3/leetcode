#include "public.h"

//16ms, 81.18%
//����ɨ��: �����³���Ϣ��¼��һ��vector<int> vabs�б�ʾ��ǰλ�����ǰһ��λ�õ�����������

class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		vector<int> vabs(1001, 0);

		for (int i = 0; i < trips.size(); ++i)
		{
			vabs[trips[i][1]] += trips[i][0];
			vabs[trips[i][2]] -= trips[i][0];
		}

		int pre = 0;
		for (int i = 0; i < 1000; ++i)
		{
			pre += vabs[i];
			if (pre > capacity) return false;
		}
		return true;
	}
};
