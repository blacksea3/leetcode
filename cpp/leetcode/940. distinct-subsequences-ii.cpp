#include "public.h"

//8ms, 85.71%
//����dp
//dp[i]:��ʾS[0]��S[i]�������и���, ����������
//dp[i] = 2*dp[i-1] - dp[last[S[i]]] ������Ϊ����������b, ����һ������b֮ǰ��x��������, ��ô��ξͻ���x���ظ�����, ��Ҫ��ȥ

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