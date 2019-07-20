#include "public.h"

//0ms, 100%
//和十进制转二进制差不多
//https://blog.csdn.net/qq_36924696/article/details/81233519

class Solution {
public:
	string baseNeg2(int N) {
		if (N == 0) return "0";
		else
		{
			string res;
			while (N != 0)
			{
				int r = abs(N % (-2));
				if (r == 1)
					res.insert(res.begin(), '1');
				else
					res.insert(res.begin(), '0');
				N = (N - r) / (-2);
			}
			return res;
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->baseNeg2(2);
	return 0;
}
*/
