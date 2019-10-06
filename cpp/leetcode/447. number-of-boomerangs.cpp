#include "public.h"

//568ms, 90.39%
//����O(n^2)
//���м�ĵ�, Ȼ����unordered_map��¼��������������ƽ���Ĵ���
//ע: �ύ���200ms�����ƺ���vector��¼�����ķ���, ʱ��Ч�ʸ���, �����븴�ӶȺܴ�

class Solution {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		int res = 0;

		for (auto& middle : points)
		{
			unordered_map<int, int> distance_squares;
			for (auto& side : points)
			{
				distance_squares[(middle[0] - side[0])*(middle[0] - side[0]) + (middle[1] - side[1])*(middle[1] - side[1])]++;
			}
			for (auto& distance_square : distance_squares)
				res += (distance_square.second - 1)*distance_square.second;
		}
		return res;
	}
};
