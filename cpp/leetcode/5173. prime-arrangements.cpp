#include "public.h"

//
//计算质数数量:
//假设有n个质数, m个非质数, 那么结果等于n!*m!

//17 : 2 3 5 7 11 13 17

class Solution {
private:
	//输入正整数, 输出是否是质数, 是就true
	bool isPrime(int n)
	{
		if (n == 1) return false;
		else if (n == 2) return true;
		else
		{
			if (n % 2 == 0) return false;

			for (int val = 3; val <= (int)sqrt(n); val += 2)
			{
				if (n%val == 0) return false;
			}
			return true;
		}
	}
	int MOD = 1000000007;

public:
	int numPrimeArrangements(int n) {
		int primeCount = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (isPrime(i)) primeCount++;
		}

		long long res = 1;
		for (int i = 1; i <= primeCount; ++i)
		{
			res *= i;
			res %= MOD;
		}
		for (int i = 1; i <= (n - primeCount); ++i)
		{
			res *= i;
			res %= MOD;
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->numPrimeArrangements(17);
	return 0;
}
*/
