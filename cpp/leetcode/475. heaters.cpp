#include "public.h"

//176ms, 6.10%
//�����ݺͼ�����λ��
//��ÿ������, �����ܺ�һ�����������������, ȡ�������
//�����н��������ҳ�����

class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		int res = 0;
		//���ǳ�ңԶ�ĵط�������������: >> 10^9, <<0
		heaters.push_back(2000000000);
		heaters.push_back(-1000000000);

		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());

		//��ÿ������, ���ܷ������Ǳ���������������
		int heaterloc = 0;

		for (int houseloc = 0; houseloc < houses.size(); ++houseloc)
		{
			while (houses[houseloc] > heaters[heaterloc + 1]) heaterloc++;
			res = max(res, min(houses[houseloc] - heaters[heaterloc],
				heaters[heaterloc + 1] - houses[houseloc]));
		}
		return res;
	}
};
