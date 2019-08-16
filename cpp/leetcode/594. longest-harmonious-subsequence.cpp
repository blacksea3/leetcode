#include "public.h"

//212ms, 18.46%
//统计数字, 找到连续的两个数字它们的出现次数之和最大

class Solution {
public:
	int findLHS(vector<int>& nums) {
		if (nums.empty()) return 0;
		map<int, int> count;
		for (auto& num : nums) count[num]++;

		int res = 0;
		map<int, int>::iterator iter = count.begin();
		int oldnum = iter->first;
		int oldcount = iter->second;

		for (iter++; iter != count.end(); ++iter)
		{
			if (iter->first == oldnum + 1)
				res = max(res, oldcount + iter->second);
			oldnum = iter->first;
			oldcount = iter->second;
		}
		return res;
	}
};
