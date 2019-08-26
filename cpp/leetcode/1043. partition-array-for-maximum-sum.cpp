#include "public.h"

//24ms, 76.53%
//dp[i]: 0-i的最大值
//dp[n] = max(所有情况: dp[j] + 之后j+1至n的值, 注意长度范围)

class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& A, int K) {
		vector<int> dp(A.size(), INT_MIN);

		for (int i = 0; i < A.size(); ++i)
		{
			int domainmax = A[i];
			for (int lastlen = 1; (lastlen <= K) && ((i - lastlen + 1) >= 0); lastlen++)
			{
				domainmax = max(domainmax, A[i - lastlen + 1]);
				if (i - lastlen >= 0)
					dp[i] = max(dp[i], dp[i - lastlen] + domainmax * lastlen);
				else
					dp[i] = max(dp[i], domainmax*lastlen);
			}
		}
		return dp[A.size() - 1];
	}
};

int main()
{
	Solution* s = new Solution();
	//vector<int> A = { 1, 15, 7, 9, 2, 5, 10 };
	//auto res = s->maxSumAfterPartitioning(A, 3);
	vector<int> A = { 7, 2 };
	auto res = s->maxSumAfterPartitioning(A, 1);
	return 0;
}
