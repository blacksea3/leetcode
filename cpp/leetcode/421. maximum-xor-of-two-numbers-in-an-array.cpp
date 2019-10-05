#include "public.h"

//120ms, 56.59%
//???这方法C++接近python3的速度, 但占用空间更大???
//原因未知

//贪心, O(n)
//使用mask: 前面多个1后面多个0
//对nums中的数字与掩模相与并存储, 然后从高到低假设当前位置可以是1, 与存储中的数字异或, 若异或结果存在于存储中, 说明确实可以是1, 否则只能是0
//从高位到低位依次判断

class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		int mask = 0;
		int nsize = nums.size();

		int temp = 0;
		int res = 0;

		for (int i = 31; i >= 0; --i)
		{
			int preBitOp = (1 << i);
			mask |= preBitOp;

			unordered_set<int> stores;
			for (auto& num:nums)
				stores.insert(num & mask);

			temp = res | preBitOp;
			for (auto& store : stores)
			{
				if (stores.find(store^temp) != stores.end())
				{
					res = temp;
					break;
				}
			}
		}
		return res;
	}
};
