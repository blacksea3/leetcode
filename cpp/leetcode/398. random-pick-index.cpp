#include "public.h"

//88ms, 99.42%
//单元素蓄水池抽样
//当当前元素是第i个等于target的元素时, 以1/i的概率用它替换之前的元素
//每个下标获取的概率则为1/n, n为nums中等于target的元素数量

class Solution {
private:
	vector<int> cpy;
public:
	Solution(vector<int>& nums) {
		cpy = nums;
	}

	int pick(int target) {
		int pre = 0;
		int loc = -1;
		//尽管给定的数字一定存在数组中, 实际上不存在的话则返回-1

		for (int i = 0; i < cpy.size(); ++i)
		{
			if (cpy[i] == target)
			{
				pre++;
				if (rand() % pre == 0) loc = i;
			}
		}
		return loc;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
