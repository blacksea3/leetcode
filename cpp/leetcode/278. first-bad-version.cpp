#include "public.h"

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);  //��������ҾͲ�ʵ����

//4ms, 89.24%
//simple solution ����

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
