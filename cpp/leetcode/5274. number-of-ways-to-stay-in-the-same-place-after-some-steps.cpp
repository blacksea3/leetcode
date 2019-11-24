#include "public.h"

//
//dp

class Solution {
public:
	int numWays(int steps, int arrLen) {
		if (arrLen == 1)
			return 1;

		long long MOD = 1000000007;

		vector<long long> dp(arrLen, 0);
		dp[0] = 1;

		for (int i = 0; i < steps; ++i)
		{
			vector<long long> tempdp = dp;
			tempdp[0] = dp[0] + dp[1];
			tempdp[0] %= MOD;

			tempdp[arrLen - 1] = dp[arrLen - 1] + dp[arrLen - 2];
			tempdp[arrLen - 1] %= MOD;

			for (int st = 1; st < (arrLen - 1); ++st)
			{
				tempdp[st] = dp[st - 1] + dp[st] + dp[st + 1];
				tempdp[st] %= MOD;
			}

			dp = tempdp;
		}
		return dp[0];
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->numWays(3,2) << endl;
	cout << s->numWays(2,4) << endl;
	cout << s->numWays(4,2) << endl;
	cout << s->numWays(10, 1) << endl;

	return 0;
}
*/
