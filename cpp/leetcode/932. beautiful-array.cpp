#include "public.h"

//36ms, 27.43%
//贪心:
//奇数全放左边: 偶数全放右边,
//奇数顺序:递归本函数, 按照返回值每个*2-1放, 偶数顺序:递归本函数, 按照返回值每个*2放

class Solution {
public:
	vector<int> beautifulArray(int N) {
		if (N == 1) return { 1 };
		else
		{
			vector<int> res;
			vector<int> odds = beautifulArray((N + 1) / 2);
			for (int i = 0; i < odds.size(); ++i)
			{
				res.push_back(2 * odds[i] - 1);
			}

			vector<int> evens = beautifulArray(N / 2);
			for (int i = 0; i < evens.size(); ++i)
			{
				res.push_back(2 * evens[i]);
			}
			return res;
		}
	}
};
