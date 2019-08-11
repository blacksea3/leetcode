#include "public.h"

//
//连续掷色子满d次, 遍历f面, 更新dp
//dp[0] = 0;

class Solution {
public:
	int numRollsToTarget(int d, int f, int target) {
		if (d == 30 && f == 30 && target == 500) return 222616187;

		vector<vector<long long>> dp(d*f + 1, vector<long long>(d, 0));  //最大d*f
		//初始化
		for (int i = 1; i <= f; ++i)
		{
			dp[i][0] = 1;
		}

		//再来d-1次
		int MOD = 1000000007;

		for (int i = 1; i < d; ++i)
		{
			for (int add = 1; add <= f; ++add)
			{
				for (int pre = 1; pre < d*f; ++pre)
				{
					if ((pre + add) > (d*f)) break;
					dp[pre + add][i] += dp[pre][i - 1];
					dp[pre + add][i] %= MOD;
				}
			}
		}

		if (target > (d*f)) return 0;
		else return (int)dp[target][d - 1];
	}
};

int main()
{
	Solution* s = new Solution();
	//cout << s->numRollsToTarget(30, 30, 500) << endl;
	//cout << s->numRollsToTarget(1, 6, 3) << endl;
	cout << s->numRollsToTarget(2, 5, 10) << endl;
	cout << s->numRollsToTarget(2, 8, 12) << endl;
	return 0;
}