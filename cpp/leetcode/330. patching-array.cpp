#include "public.h"

//8ms, 94.59%
/*
参考至作者：Faber99
链接：https ://leetcode-cn.com/problems/two-sum/solution/an-yao-qiu-bu-qi-shu-zu-tan-lan-by-faber99/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

假如现在有一个数组nums，满足1 - n均可由数组nums构成，此时添加一个元素num，有如下两种情况： 1，num > n：
nums数组可表示的连续的值范围： 1 - n && num - num + n， 中间n - num是没法表示的；
2，num <= n:
nums数组可表示的连续的值范围 可向前延伸 num个长度：即由1 - n 变成了 1 - n + num。
因为数组是有序的正整数，所以根据从小到大，根据以上两种情况 不断延长 可表示的连续值范围，直到1 - n均可被表示。

考虑到nums已从小到大排序, 那么遍历, 对于情况1, 额外增加一个数字n+1, 使得可表示连续值范围变成2n+1, 这是最优的(我不会证明)
对于情况2, 直接更新可表示连续值范围至n + num (注意代码: 实际实现的时候保存的值presum对应可表示的连续值范围是[1,presum))

遍历结束如果还是没有到要求, 那么对当前可表示连续值*2 *2 ... 直至达到了要求

*/

class Solution {
public:
	int minPatches(vector<int>& nums, int n) {
		long presum = 1;  //注意: 实际的可表示的连续值范围是[1,presum)
		int res = 0;

		for (auto& in : nums)
		{
			if (in > n) break;
			while (in > presum)
			{
				res++;
				presum *= 2;
			}
			presum += in;
		}

		while (presum <= n)
		{
			res++;
			presum *= 2;
		}
		return res;
	}
};

