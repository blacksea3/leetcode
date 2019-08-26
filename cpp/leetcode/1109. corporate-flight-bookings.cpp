#include "public.h"

//336ms, 91.16%
//O(n)ɨ��
//��bookings�洢��vabs, ��ʾ��ǰĳ���������λ�����ǰһ�κ����ƫ��ֵ

class Solution {
public:
	vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
		int* vabs = new int[n + 2];
		memset(vabs, 0, (n + 2) * 4);
		vector<int> res(n + 1, 0);

		for (int i = 0; i < bookings.size(); ++i)
		{
			vabs[bookings[i][0]] += bookings[i][2];
			vabs[bookings[i][1] + 1] -= bookings[i][2];
		}

		for (int i = 1; i <= n; ++i)
			res[i] = res[i - 1] + vabs[i];
		res.erase(res.begin());
		return res;
	}
};
