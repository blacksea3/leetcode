#include "public.h"

//164ms, 61.70%
//ͳ��, Ȼ��ע���ж�˳��, �����ж�
//ͳ�ƽ��ֱ�ӷ���vector<int> v(200001, 0)��, �����±����ʵ��ֵ+100000

class Solution {
public:
	bool canReorderDoubled(vector<int>& A) {
		vector<int> v(200001, 0);

		for (auto& a : A)
			v[a + 100000]++;

		//����
		for (int i = 0; i < 100000; ++i)
		{
			if (v[i] > 0)
			{
				if (i % 2) return false;
				else
				{
					int temp = i / 2 + 50000;
					if (v[temp] < v[i]) return false;
					else v[temp] -= v[i];
				}
			}
		}

		//����
		for (int i = 200000; i >= 100001; --i)
		{
			if (v[i] > 0)
			{
				if (i % 2) return false;
				else
				{
					int temp = i / 2 + 50000;
					if (v[temp] < v[i]) return false;
					else v[temp] -= v[i];
				}
			}
		}
		return true;
	}
};
