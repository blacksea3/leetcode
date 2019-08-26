#include "public.h"

//8ms, 98.21%
//O(n) 考虑题意: 必然存在一条分界线: 把A拆分成两半, 对左半边: 寻找连续长度为L或M的子数组
// 对右半边: 寻找另一部分

//引入dp[i][0]: 从A[0]-A[i]连续L长度子数组最大的元素和
//dp[i][1]: 从A[0]-A[i]连续M长度子数组最大的元素和
//dp[i][2]: 从A[i]-A[A.size()-1]连续L长度子数组最大的元素和
//dp[i][3]: 从A[i]-A[A.size()-1]连续M长度子数组最大的元素和
//超出范围则为dump: 0

class Solution {
public:
	int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
		//计算dp, 4个滑动窗口, 4种情况
		vector<vector<int>> dp(A.size(), vector<int>(4, 0));
		int presum = 0;
		int maxsum;
		for (int i = 0; i < L; ++i)
		{
			presum += A[i];
		}
		maxsum = presum;
		dp[L - 1][0] = maxsum;
		for (int i = L; i < A.size(); ++i)
		{
			presum -= A[i - L];
			presum += A[i];
			maxsum = max(maxsum, presum);
			dp[i][0] = maxsum;
		}

		presum = 0;
		for (int i = 0; i < M; ++i)
		{
			presum += A[i];
		}
		maxsum = presum;
		dp[M - 1][1] = maxsum;
		for (int i = M; i < A.size(); ++i)
		{
			presum -= A[i - M];
			presum += A[i];
			maxsum = max(maxsum, presum);
			dp[i][1] = maxsum;
		}

		presum = 0;
		for (int i = A.size() - 1; i >= A.size() - L; --i)
		{
			presum += A[i];
		}
		maxsum = presum;
		dp[A.size() - L][2] = maxsum;
		for (int i = A.size() - L - 1; i >= 0; --i)
		{
			presum -= A[i + L];
			presum += A[i];
			maxsum = max(maxsum, presum);
			dp[i][2] = maxsum;
		}

		presum = 0;
		for (int i = A.size() - 1; i >= A.size() - M; --i)
		{
			presum += A[i];
		}
		maxsum = presum;
		dp[A.size() - M][3] = maxsum;
		for (int i = A.size() - M - 1; i >= 0; --i)
		{
			presum -= A[i + M];
			presum += A[i];
			maxsum = max(maxsum, presum);
			dp[i][3] = maxsum;
		}

		//计算答案
		int res = 0;
		//L在M左边
		for (int i = L; i <= A.size() - M; ++i)
			res = max(res, dp[i - 1][0] + dp[i][3]);
		//M在L左边
		for (int i = M; i <= A.size() - L; ++i)
			res = max(res, dp[i - 1][1] + dp[i][2]);

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = { 0, 6, 5, 2, 2, 5, 1, 9, 4 };
	auto res = s->maxSumTwoNoOverlap(A, 1, 2);
	return 0;
}
*/
