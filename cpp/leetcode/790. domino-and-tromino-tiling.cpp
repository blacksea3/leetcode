#include "public.h"

//16ms, 14.55%
//dp����
//N=1: 1��, N=2:2��, N=3 ���� dp[1]*dp[2] + 2��, ֮�� 

//֮��: dp[i] = ��һ������ô����dp[i-1]��, ����ǰ��������ô����dp[i-2]��, ���ߵ�һ�����۽���ô��2*(dp[i-3]��...��) + ������ֱ�ǰ�ס2��

class Solution {
public:
	int numTilings(int N) {
		if (N == 1) return 1;
		else if (N == 2) return 2;
		int MOD = 1000000007;

		vector<int> dp(N + 1); //dp[0]:dump
		dp[1] = 1;
		dp[2] = 2;

		for (int i = 3; i <= N; ++i)
		{
			long long pre = dp[i - 1] + dp[i - 2];
			for (int j = i - 3; j >= 1; --j)
			{
				pre += 2 * dp[j];
			}
			pre += 2;
			pre %= MOD;
			dp[i] = pre;
		}
		return dp[N];
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->numTilings(4);
	return 0;
}
