#include "public.h"

//8ms, 79.53%
//ͳ�Ƹ������ֳ��ֵ�Ƶ��
//����i ������j ��, res += ����(j�Ƿ�������(i+1)����)

class Solution {
public:
	int numRabbits(vector<int>& answers) {
		unordered_map<int, int> um;

		for (auto& a : answers)
		{
			um[a]++;
		}

		int res = 0;
		for (auto& ium : um)
		{
			if (ium.second % (ium.first + 1) == 0)
			{
				res += (ium.first + 1)*(ium.second / (ium.first + 1));
			}
			else
			{
				res += (ium.first + 1)*(ium.second / (ium.first + 1) + 1);
			}
		}
		return res;
	}
};
