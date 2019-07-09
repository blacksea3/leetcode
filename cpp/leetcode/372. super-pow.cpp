#include "public.h"

//12ms, 94.62%
/*
a^ b % c = (a % c)^ b % c
= ((a % c)^ (b-t) * (a % c)^ t ) % c
令 t = b / 2：原式可化为 = ((a % c)^ b/2 * (a % c)^ (b-b/2) ) % c
当 t = 1时，(a % c) t = a % c;
当 t = 0时，(a % c) t = 1;
---------------------
作者：hestyle
来源：CSDN
原文：https://blog.csdn.net/qq_41855420/article/details/88563206
版权声明：本文为博主原创文章，转载请附上博文链接！

*/

class Solution {
public:
	int superPow(int a, vector<int>& b) {
		long long res = 1;
		for (int i = 0; i < b.size(); ++i) {
			//pow(res, 10)是这一位的权
			res = pow(res, 10) * pow(a, b[i]) % 1337;
		}
		return res;
	}
	int pow(int x, int n) {
		if (n == 0) {
			return 1;
		}
		if (n == 1) {
			return x % 1337;
		}
		//利用公式将n对半分
		return pow(x % 1337, n / 2) * pow(x % 1337, n - n / 2) % 1337;
	}
};
