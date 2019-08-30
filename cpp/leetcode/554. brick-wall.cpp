#include "public.h"

//60ms, 90.31%
//����: ͳ��ÿһ�е�ǰn���, ��¼��unordered_map, ͳ��ǰn��ͳ��ִ�������
//���ǵ���ש������<=20000, ��������

class Solution {
public:
	int leastBricks(vector<vector<int>>& wall) {
		unordered_map<int, int> count;

		for (auto& iter_wall : wall)
		{
			int preSum = 0;
			for (int index = 0; index < iter_wall.size() - 1; ++index)
			{
				preSum += iter_wall[index];
				count[preSum]++;
			}
		}

		int maxCount = 0;

		for (auto& iter_count : count)
		{
			if (iter_count.second > maxCount)
			{
				maxCount = iter_count.second;
			}
		}
		return wall.size() - maxCount;
	}
};
