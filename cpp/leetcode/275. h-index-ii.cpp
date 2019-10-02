#include "public.h"

//12ms, 100%
//二分

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int cSize = citations.size();
		// 特判
		if (cSize == 0 || citations[cSize - 1] == 0) return 0;

		int left = 0;
		int right = cSize - 1;
		while (left < right)
		{
			int mid = (left + right) / 2;
			// 比长度小，就得去掉该值
			if (citations[mid] < cSize - mid) {
				left = mid + 1;
			}
			else {
				// 比长度大是满足的，我们应该继续让 mid 往左走去尝试看有没有更小的 mid 值
				// 可以满足 mid 对应的值大于等于从 [mid, cSize - 1] 的长度
				right = mid;
			}
		}
		return cSize - left;
	}
};


//20ms, 91.95%
//O(n)
//类似274题, 一篇一篇引用次数降序 数 文章数

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int i = 0;
		int cSize = citations.size();

		while ((i < cSize) && (citations[cSize - i - 1] > i)) i++;
		return i;
	}
};
