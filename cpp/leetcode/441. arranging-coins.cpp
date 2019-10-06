#include "public.h"

//4ms, 95.86%
//二分
//结果r应当满足:  r*(r + 1)/2 <= n; (r+1)*(r+2)/2 > n

class Solution {
public:
	int arrangeCoins(int n) {
		long long le = 0;
		long long ri = n;

		while (le < ri)
		{
			long long mid = (le + ri) / 2;
			if (mid*(mid + 1) / 2 > n)
			{
				ri = mid - 1;
			}
			else if ((mid + 1)*(mid + 2) / 2 <= n)
			{
				le = mid + 1;
			}
			else
			{
				return mid;
			}
		}
		return le;
	}
};

//12ms, 67.06%
/*
//暴力模拟
class Solution {
public:
	int arrangeCoins(int n) {
		int line = 1;

		while (n >= line)
		{
			n -= line;
			line++;
		}
		return line;
	}
};
*/
