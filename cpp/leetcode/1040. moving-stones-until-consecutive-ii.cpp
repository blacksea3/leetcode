#include "public.h"

//56ms, 27.17%
//最大值:
//对所有介于石子位置: 最大值与最小值之间都填充, 但是若最小位置和次小位置之间有空隙/最大位置和次大位置之间有空隙, 那么需要去除两个空隙中的小的值
//最小值:
//找一个长度为stones.size()的连续位置序列, 能最多覆盖已有的石子, 其他石子放进空隙位置,
//但特殊情况是: 除了最边上的一个石子(最小位置或最大位置), 其他石子都连续, 那么这得放两次

class Solution {
public:
	vector<int> numMovesStonesII(vector<int>& stones) {
		//排序
		sort(stones.begin(), stones.end());

		//最大值
		int maxnum = stones[stones.size() - 1] - stones[0] - stones.size() + 1;
		int passloc = min(stones[stones.size() - 1] - stones[stones.size() - 2], stones[1] - stones[0]) - 1;

		//最小值
		//先排除特殊情况
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
