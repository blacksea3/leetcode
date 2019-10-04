#include "public.h"

//36ms, 93.40%
//二分, 被查找的值一定在最大值和最小值之间, 然后逐次搜索每一行比中间值大的数字的个数

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int lo = matrix[0][0], hi = matrix.back().back();
		
		while (lo < hi)
		{
			int mid = lo + (hi - lo >> 1);
			int count = 0;
			// O(n)
			for (auto& m:matrix) 
			{
				// O(logn)
				// <= mid 的元素个数
				count += upper_bound(m.begin(), m.end(), mid) - m.begin();
			}
			if (k <= count) {
				hi = mid;
			}
			else {
				lo = mid + 1;
			}
		}
		return lo;
	}
};
