#include "public.h"

//40ms, 88.33%
//��¼�������Ƶ����vector, Ȼ�󰤸�����
//������˼��: ����������, �����Խ�<=��������> 0.5*�Լ�����+7��

class Solution {
public:
	int numFriendRequests(vector<int>& ages) {
		vector<int> va(121, 0);  //va[0] is dump
		for (auto& a : ages) va[a]++;

		int res = 0;

		//�ϲ�
		for (int i = 1; i <= 120; ++i)
		{
			for (int j = 0.5*i + 8; j <= i; ++j)
			{
				if (i != j) res += va[i] * va[j];
				else res += (va[i] * (va[i] - 1));
			}
		}

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> ages = { 101, 56, 69, 48, 30 };
	cout << s->numFriendRequests(ages);
	return 0;
}
*/
