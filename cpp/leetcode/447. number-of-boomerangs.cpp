#include "public.h"

//824ms, 52.35%
//�뱩��
//���м�ĵ�, Ȼ������������������ƽ��, ͳ��Ƶ��
//�ô�����long long, ��ֹ���

class Solution {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		int res = 0;

		for (auto& middle : points)
		{
			unordered_map<long long, int> distance_squares;

			for (auto& side : points)
			{
				distance_squares[((long long)middle[0] - side[0])*((long long)middle[0] - side[0]) + ((long long)middle[1] - side[1])*((long long)middle[1] - side[1])]++;
			}

			for (auto& distance_square : distance_squares)
				res += (distance_square.second - 1)*distance_square.second;
		}

		return res;
	}
};

