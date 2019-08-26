#include "public.h"

//40ms, 28.75%
//贪心
//允许搜索的范围: 例如num.size() = 5, k=2, 则第一个数的loc允许搜索的范围是0,1,2,3
//在允许搜索的范围内搜素这样的loc: num[loc+1] < num[loc], 若不存在, 则删除允许搜索的范围内最大的loc

class Solution {
public:
	string removeKdigits(string num, int k) {

		//贪心
		//注意到nums.size() >= k
		//最坏情况会O(n^2)

		while (k > 0)
		{
			//寻找
			int loc;
			for (loc = 0; loc <= num.size() - k - 1; ++loc)
			{
				if (num[loc + 1] < num[loc]) break;
			}

			//删去
			num.erase(num.begin() + loc);
			k--;
		}

		int begin = 0;
		while (begin < num.size() && num[begin] == '0') begin++;
		return num.substr(begin) == "" ? "0" : num.substr(begin);
	}
};
