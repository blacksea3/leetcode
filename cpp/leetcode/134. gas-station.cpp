#include "public.h"

//4ms, 99.82%
//̰��
//��ʼ��ʻ,���ĳ��·�ڽ�β���ͱ�ɸ�����,��������ʼ��,��ס֮ǰ����ֵ(��������֮ǰ�ĸ���ֵ����)
//������Ϊ�����ʼ�����Ƕ��м�Ļ�,�����Ƕ�·û����β�������ģ������һ���͸��ĸ����������迼�ǡ�
//������������,�Ѷ��������ǰ����ܼƸ���ֵ�Ƚ�, �ó�����

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int pre_init = 0;
		int pre_nagative_res = 0;
		int startloc = 0;

		for (int i = 0; i < gas.size(); i++)
		{
			pre_init += gas[i] - cost[i];
			if (pre_init < 0)
			{
				pre_nagative_res += pre_init;
				pre_init = 0;
				startloc = (i + 1);
			}
		}

		return ((pre_init + pre_nagative_res) >= 0) ? startloc : -1;
	}
};
