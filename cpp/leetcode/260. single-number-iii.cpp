#include "public.h"

//16ms, 90.54%
//位运算
//先全部异或一遍
//得到两个不同数字的异或值
//然后寻找到这个值的最末尾一个1(或任意位置的1)

//对所有数, 如果此bit为1,分为一组;为0分为另一组
//那么两个只出现一次的数字必然分开在两组里面

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int s = 0;
		for (auto& n : nums) s ^= n;

		int mask = s & (-s) & 0x7FFFFFFF;

		vector<int> res(2, 0);
		for (auto& n : nums)
		{
			if (n&mask) res[0] ^= n;
			else res[1] ^= n;
		}
		return res;
	}
};
