#include "public.h"

//滑动窗口, 12ms, 94.53%

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		//直接来O(n)解法
		//滑动窗口
		queue<int> pre;
		int presum = 0;
		int loc = 0;
		int minlen = INT_MAX;
		while (loc < nums.size())
		{
			pre.push(nums[loc]);
			presum += nums[loc];
			if (presum >= s)
			{
				while (presum >= s)
				{
					presum -= pre.front();
					pre.pop();
				}
				minlen = (pre.size() + 1 < minlen) ? pre.size() + 1 : minlen;
			}
			++loc;
		}
		//按理来说,minlen不会真的是INT_MAX吧,...
		return (minlen != INT_MAX) ? minlen : 0;
	}
};

