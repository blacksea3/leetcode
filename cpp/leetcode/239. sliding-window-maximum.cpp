#include "public.h"

//72ms, 97.96%
//双向队列
//考虑到以下的情形:1 4 3 6 2 5, k=4
//初始化双向队列, 遍历4个数, 如果当前数比队列末尾数更大, 则去掉队列末尾数, 直到当前数比队列末位数小, 记录坐标至末尾
//这样使得双向队列从头到尾的坐标对应的数一定是最大到最小, 而且从头到尾坐标逐渐增大

//然后遍历剩下来的数, 维持这个双向队列即可

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int nsize = nums.size();
		if (nsize == 0) return {};
		vector<int> res;
		deque<int> dq;

		//init
		for (int i = 0; i < k; ++i)
		{
			while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
			dq.push_back(i);
		}
		res.push_back(nums[dq.front()]);

		for (int i = k; i < nsize; ++i)
		{
			if (dq.front() <= (i - k)) dq.pop_front();
			while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
			dq.push_back(i);
			res.push_back(nums[dq.front()]);
		}
		return res;
	}
};

