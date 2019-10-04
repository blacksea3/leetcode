#include "public.h"

//4ms, 97.30%
//贪心
//允许搜索的范围: 例如num.size() = 5, k=2, 则第一个数的loc允许搜索的范围是0,1,2,3
//在允许搜索的范围内搜素这样的loc: num[loc+1] < num[loc], 若不存在, 则删除允许搜索的范围内最大的loc
//这个可以用单调栈实现, num从左往右遍历, 若栈顶元素大于当前元素则删除栈顶元素
//如果删除元素数量不够, 那么从num最后的元素开始删除
//O(n)

class Solution {
public:
	string removeKdigits(string num, int k) {
		int delK = 0;
		int nIndex = 0;
		string res;
		int resSize = num.size() - k;

		for (char& c : num)
		{
			while (k && !res.empty() && res.back() > c)  //这可以让res最多删除k个元素(res实际上添加了num的所有元素)
			{
				res.pop_back();
				--k;
			}
			res.push_back(c);
		}
		res.resize(resSize);  //如果删除元素不够, 则截断最后的元素

		while (!res.empty() && res[0] == '0') res.erase(res.begin());
		return res.empty() ? "0" : res;
	}
};
