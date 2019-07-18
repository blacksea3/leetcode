#include "public.h"

//164ms, 89.55%
//暴力: 直接保存, 按距离排序

class Solution {
private:
	static bool msort(vector<int> &a, vector<int> &b)    //根据曼哈顿距离升序排序
	{
		return a[2] < b[2];
	}

public:
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		vector<vector<int>> res;

		for (int r = 0; r < R; ++r)
		{
			for (int c = 0; c < C; ++c)
			{
				res.push_back({ r, c, abs(r - r0) + abs(c - c0) });
			}
		}

		sort(res.begin(), res.end(), msort);

		for (int i = 0; i < res.size(); ++i) res[i].erase(res[i].begin() + 2);

		return res;

	}
};

int main()
{
	Solution* s = new Solution();
	auto res = s->allCellsDistOrder(1,2,0,0);
	return 0;
}