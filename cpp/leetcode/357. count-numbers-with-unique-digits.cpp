#include "public.h"

//0ms, 100%
//数学题, DP solution
//dp[i]: i-1位数的各位数字都不同的数字的个数
//dp[0]: 1
//dp[1]: 9
//以下为规律
//dp[2]: 9*dp[1]
//dp[3]: 8*dp[2]
//dp[4]: 7*dp[3]...
//...
//然后求个和

class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n >= 10) return 0;
		else
		{
			vector<int> dp(n + 1, 1);
			if (n == 0) return 1;
			else
			{
				dp[1] = 9;
				for (int i = 2; i <= n; ++i)
				{
					dp[i] = (11 - i)*dp[i - 1];
				}
				return accumulate(dp.begin(), dp.end(), 0);
			}
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->countNumbersWithUniqueDigits(2);
	return 0;
}
*/
