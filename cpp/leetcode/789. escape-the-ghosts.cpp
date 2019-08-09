#include "public.h"

//12ms, 65.28%
//�жϾ���: ֻҪ�谭�ߵ���̵�һ������<=�ҵľ�����ôfalse, ����true, �������پ���

class Solution {
public:
	bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
		int minghosts_dis = INT_MAX;

		for (auto& g : ghosts)
		{
			minghosts_dis = min(minghosts_dis, abs(g[0] - target[0]) + abs(g[1] - target[1]));
		}

		int my_dis = abs(target[0]) + abs(target[1]);

		return my_dis < minghosts_dis;
	}
};
