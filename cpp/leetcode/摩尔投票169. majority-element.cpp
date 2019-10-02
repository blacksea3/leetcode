#include "public.h"

//Boyer-Moore 算法 20ms, 91.37%
/*
我们维护一个计数器，如果遇到一个我们目前的候选众数，就将计数器加一，否则减一。只要计数器等于 0 ，
我们就将 nums 中之前访问的数字全部 忘记 ，并把下一个数字当做候选的众数。

作者：LeetCode
链接：https://leetcode-cn.com/problems/two-sum/solution/qiu-zhong-shu-by-leetcode-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int res = 0;
		int vote = 0;

		for (auto& n : nums)
		{
			if (vote == 0) res = n;

			if (res == n) vote++;
			else vote--;
		}
		return res;
	}
};
