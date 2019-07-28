#include "public.h"

//8ms, 85.71%
//复杂dp
//dp[i]:表示S[0]至S[i]的子序列个数, 包含空序列
//dp[i] = 2*dp[i-1] - dp[last[S[i]]] 这是因为如果这次增加b, 而上一次增加b之前有x个子序列, 那么这次就会有x个重复序列, 需要减去

class Solution {
public:
	int distinctSubseqII(string S) {
		long MOD = 1000000007;

		vector<long> dp(S.size(), 0);
		dp[0] = 2;
		vector<int> last(26, -1);

		for (int i = 1; i < S.size(); ++i)
		{
			dp[i] = (2 * dp[i - 1]) % MOD;
			if (last[S[i] - 'a'] >= 0)
				dp[i] -= dp[last[S[i] - 'a']];
			dp[i] %= MOD;
			last[S[i] - 'a'] = i - 1;
		}
		return dp[S.size() - 1] - 1;
	}
};

int main()
{
	Solution* s = new Solution();
	auto res = s->distinctSubseqII("aba");
	return 0;
}