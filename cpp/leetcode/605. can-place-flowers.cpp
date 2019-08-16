#include "public.h"

//28ms, 32.67%
//多次计算相邻的1之间的距离, 计算即可
//边界条件: 假设第一个1的索引是-2, 最后一个1的索引是flowerbed.size() + 1

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int oldloc = -2;
		int res = 0;       // abs = 1,2,3, res += 0, abs = 4,5 res += 1, abs = 6, 7 res += 3...

		for (int i = 0; i < flowerbed.size(); ++i)
		{
			if (flowerbed[i] == 1)
			{
				res += max(0, (i - oldloc - 2) / 2);
				oldloc = i;
			}
		}

		res += max(0, ((int)flowerbed.size() + 1 - oldloc - 2) / 2);
		return res >= n;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> flowerbed = {1, 0, 0, 0, 1};
	cout << s->canPlaceFlowers(flowerbed, 2);
	return 0;
}
*/
