#include "public.h"

//贪心
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
			mask |= (1 << i);

			unordered_set<int> stores;
			for (int j = 0; j < nsize; ++j)
				stores.insert(nums[j] & mask);

			temp = res | (1 << i);

			for (auto& store : stores)
			{
				if (stores.find(store^temp) != stores.end())
				{
					res |= (1 << i);
					break;
				}
			}
		}
		return res;
	}
};
