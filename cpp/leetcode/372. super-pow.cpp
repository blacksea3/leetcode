#include "public.h"

//12ms, 94.62%
/*
a^ b % c = (a % c)^ b % c
= ((a % c)^ (b-t) * (a % c)^ t ) % c
�� t = b / 2��ԭʽ�ɻ�Ϊ = ((a % c)^ b/2 * (a % c)^ (b-b/2) ) % c
�� t = 1ʱ��(a % c) t = a % c;
�� t = 0ʱ��(a % c) t = 1;
---------------------
���ߣ�hestyle
��Դ��CSDN
ԭ�ģ�https://blog.csdn.net/qq_41855420/article/details/88563206
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�

*/

class Solution {
public:
	int superPow(int a, vector<int>& b) {
		long long res = 1;
		for (int i = 0; i < b.size(); ++i) {
			//pow(res, 10)����һλ��Ȩ
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
		//���ù�ʽ��n�԰��
		return pow(x % 1337, n / 2) * pow(x % 1337, n - n / 2) % 1337;
	}
};
