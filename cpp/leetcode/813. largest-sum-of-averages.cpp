#include "public.h"

//128ms, 5.45%
//dp
//dp[i][j][k]: 最后一部分是A[i]至A[j], 已经划分了k部分, 最大的值
//则更新: 主j(0<=j<A.size()-1)循环, 次k循环(0<k<=min(j+1, K)), 然后i循环(i<=j), dp[i][j+1][k] 等于dp[i][j][k] - (A[i]至A[j]平均值) + (A[i]至A[j+1]平均值)
//最后dp[j+1][j+1][k+1]等于对于所有的i dp[i][j][k]中的最大值 + A[j+1]

//边界条件: 如果当前k已经=K了, 那么无需第二种更新
//结果: 对于所有的i, j, 寻找最大的dp[i][j][K]
//初始化: dp[0][0][1] = A[0]

class Solution {
public:
	double largestSumOfAverages(vector<int>& A, int K) {
		int as = A.size();
		vector<vector<vector<double>>> dp(as, vector<vector<double>>(as, vector<double>(K + 1, INT_MIN)));

		vector<double> sum(as + 1);
		int presum = 0;
		for (int i = 1; i <= as; ++i)
		{
			presum += A[i - 1];
			sum[i] = presum;
		}

		dp[0][0][1] = A[0];

		for (int j = 0; j < as - 1; ++j)
		{
			for (int k = 1; k <= min(j + 1, K); ++k)
			{
				for (int i = 0; i <= j; ++i)
				{
					dp[i][j + 1][k] = dp[i][j][k] - (sum[j + 1] - sum[i]) / (double)(j + 1 - i) + (sum[j + 2] - sum[i]) / (double)(j + 2 - i);
				}
				if (k != K)
				{
					double tempmax = INT_MIN;
					for (int i = 0; i <= j; ++i)
					{
						tempmax = max(tempmax, dp[i][j][k]);
					}
					dp[j + 1][j + 1][k + 1] = tempmax + A[j + 1];
				}
			}
		}

		double resmax = INT_MIN;
		for (int i = 0; i < as; ++i)
		{
			resmax = max(resmax, dp[i][as - 1][K]);
		}
		return resmax;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = {9, 1, 2, 3, 9};
	cout << s->largestSumOfAverages(A, 3);
	return 0;
}
*/
