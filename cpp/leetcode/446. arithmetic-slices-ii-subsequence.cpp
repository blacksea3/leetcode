#include "public.h"

//804ms, 85.57%
//定义f[i][d]: 以A[i]结尾公差为d的等差数列(长度>=2)
//则f[i][A[i]-A[j]] = f[j][A[i]-A[j]] + 1, 其中f[j][A[i]-A[j]]是包含A[i]的长度>=3的等差数列数量, +1是当前A[i]和A[j]构成的长度等于2的数列
//对每次求解的f[j][A[i]-A[j]]求和即可

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int res = 0;
		int ASize = A.size();
		vector<unordered_map<long long, int>> dp(A.size());

		for (int i = 1; i < ASize; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				long long delta = (long long)A[i] - A[j];
				if (dp[j].find(delta) != dp[j].end())
				{
					dp[i][delta] += dp[j][delta];
					res += dp[j][delta];
				}
				dp[i][delta]++;
			}
		}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> A = { 2,2,3,4 };
	cout << s->numberOfArithmeticSlices(A);
	return 0;
}
