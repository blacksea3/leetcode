#include "public.h"

//��������, 12ms, 94.53%

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		//ֱ����O(n)�ⷨ
		//��������
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
		//������˵,minlen���������INT_MAX��,...
		return (minlen != INT_MAX) ? minlen : 0;
	}
};

