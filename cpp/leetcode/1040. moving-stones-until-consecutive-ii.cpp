#include "public.h"

//56ms, 27.17%
//���ֵ:
//�����н���ʯ��λ��: ���ֵ����Сֵ֮�䶼���, ��������Сλ�úʹ�Сλ��֮���п�϶/���λ�úʹδ�λ��֮���п�϶, ��ô��Ҫȥ��������϶�е�С��ֵ
//��Сֵ:
//��һ������Ϊstones.size()������λ������, ����า�����е�ʯ��, ����ʯ�ӷŽ���϶λ��,
//�����������: ��������ϵ�һ��ʯ��(��Сλ�û����λ��), ����ʯ�Ӷ�����, ��ô��÷�����

class Solution {
public:
	vector<int> numMovesStonesII(vector<int>& stones) {
		//����
		sort(stones.begin(), stones.end());

		//���ֵ
		int maxnum = stones[stones.size() - 1] - stones[0] - stones.size() + 1;
		int passloc = min(stones[stones.size() - 1] - stones[stones.size() - 2], stones[1] - stones[0]) - 1;

		//��Сֵ
		//���ų��������
		int minnum;
		if (stones[stones.size() - 1] - stones[0] == stones.size() - 1) minnum = 0;
		else if (stones[stones.size() - 1] - stones[0] == stones.size()) minnum = 1;
		else if (stones[stones.size() - 2] - stones[0] == stones.size() - 2) minnum = 2;
		else if (stones[stones.size() - 1] - stones[1] == stones.size() - 2) minnum = 2;
		else
		{
			int maxoccupy = INT_MIN;
			for (int i = 0; i < stones.size(); ++i)
			{
				vector<int>::iterator largerloc = upper_bound(stones.begin(), stones.end(), stones[i] + stones.size() - 1);
				maxoccupy = max(maxoccupy, (int)(largerloc - stones.begin() - i));
			}
			minnum = stones.size() - maxoccupy;
		}
		vector<int> res = { minnum, maxnum - passloc};
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> stones = { 7, 4, 9 };
	auto res = s->numMovesStonesII(stones);
	return 0;
}*/
