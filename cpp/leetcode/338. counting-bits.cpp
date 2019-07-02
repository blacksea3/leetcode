#include "public.h"

//80ms, 92.35%
//考虑下面的规律:
//每个数组n的1个个数取决于其的末尾是否是1以及它除以2的整数(int)n/2的1的个数

class Solution {
public:
	vector<int> countBits(int num) {
		//每次更新2^n个数
		vector<int> res(num + 1, 0);

		for (int i = 1; i <= num; ++i)
			res[i] = res[i >> 1] + i % 2;

		return res;
	}
};


/*
128ms, 32.84%
//考虑下面的规律:
//注意到: 例如: 最开始的4个数和其次4个数二进制上仅仅差一个第三位
//有以下的规律: 0 -> 0 1 -> 01 12 -> 01121223
//每次计算1,2,4,8...的数量的数据, 后2^n个值等于前2^n个值相对位置加1

class Solution {
public:
	vector<int> countBits(int num) {
		//每次更新2^n个数
		int prelen = 1;
		vector<int> res(1, 0);

		while (2 * prelen <= num + 1)
		{
			for (int i = 0; i < prelen; ++i)
				res.push_back(res[i] + 1);
			prelen *= 2;
		}
		//最后一轮添加
		for (int i = 0; i < (num + 1 - prelen); ++i)
			res.push_back(res[i] + 1);

		return res;
	}
};
*/

