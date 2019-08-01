#include "public.h"

//268ms, 6.82%
//排序: 从小到大: 最大值贡献: 等于某个数乘上2^(比他大的数的个数)
//若多个数相等, 不要紧

class Solution {
private:
	int M = 1000000007;
	//返回: a*(2^^(pow))
	long long mi(long long a, long long k, int mulfac)
	{
		long long b = 1;
		while (k >= 1) {
			if (k % 2 == 1) {
				b = a * b%M;
			}
			a = (a%M)*(a%M) % M;
			k /= 2;
		}
		b *= mulfac;
		b %= M;
		return b;
	}

public:
	int sumSubseqWidths(vector<int>& A) {
		sort(A.begin(), A.end());

		int minres = 0;
		for (int i = 0; i < A.size(); ++i)
		{
			minres += mi(2, A.size() - 1 - i, A[i]);
			minres %= M;
		}

		int maxres = 0;
		for (int i = A.size() - 1; i >= 0; --i)
		{
			maxres += mi(2, i, A[i]);
			maxres %= M;
		}

		int res = maxres - minres;

		return (res >= 0) ? res : (res + M);
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = { 5,69,89,92,31,16,25,45,63,40,16,56,24,40,75,82,40,12,50,62,92,44,67,38,92,22,91,24,26,21,100,42,23,56,64,43,95,76,84,79,89,4,16,94,16,77,92,9,30,13 };
	cout << s->sumSubseqWidths(A);
	return 0;
}
*/
