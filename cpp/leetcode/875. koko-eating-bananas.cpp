#include "public.h"

//76ms, 70.34%
//二分查结果:
//应当存在这样的一个值x: 用x-1速度吃香蕉, 小时数>H, 用x速度吃香蕉小时数<=H

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
