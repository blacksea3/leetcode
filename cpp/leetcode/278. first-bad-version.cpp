#include "public.h"

//4ms, 69.67%
//二分
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);  //这个函数我就不实现了

class Solution {
public:
	int firstBadVersion(int n) {
		int left = 1;
		int right = n;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;

			if (isBadVersion(mid)) right = mid - 1;
			else left = mid + 1;
		}

		return left;
	}
};
