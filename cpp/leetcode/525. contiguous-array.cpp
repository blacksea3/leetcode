#include "public.h"

//188ms, 55.65%
//用unordered_map记录特定值:x第一次在nums中出现的index, 此值x表示从开头开始的0数量减去1数量
//初始化unordered_map[0] = -1
//则第二次出现这个值的时候, 中间的连续子数组的0数量和1数量相同

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int preX = 0;
		unordered_map<int, int> count;
		count[0] = -1;
		int res = 0;

		for (int index = 0; index < nums.size(); ++index)
		{
			if (nums[index] == 0)
			{
				preX++;
			}
			else
			{
				preX--;
			}

			if (count.find(preX) == count.end())
			{
				count[preX] = index;
			}
			else
			{
				res = max(res, index - count[preX]);
			}
		}
		return res;
	}
};
