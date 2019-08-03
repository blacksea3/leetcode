#include "public.h"

//76ms, 70.34%
//���ֲ���:
//Ӧ������������һ��ֵx: ��x-1�ٶȳ��㽶, Сʱ��>H, ��x�ٶȳ��㽶Сʱ��<=H

class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int H) {
		int left = 1;
		int right = *max_element(piles.begin(), piles.end());

		while (left <= right)
		{
			int pre = 0;
			int mid = (left + right) / 2;
			if (mid == 0)
			{
				left = mid + 1;
				continue;
			}
			for (auto& p : piles)
			{
				if (p%mid) pre += p / mid + 1;
				else pre += p / mid;
			}
			if (pre > H)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return left;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<int> piles = { 3,6,7,11 };
	//cout << s->minEatingSpeed(piles, 8);
	vector<int> piles2 = { 30,11,23,4,20 };
	cout << s->minEatingSpeed(piles2, 6);
	return 0;
}
*/
