#include "public.h"

//还有拉格朗日四数平方法, 看不懂, 以后再优化
//DP problem, 252ms, 22.08%, 据说python 这样的DP会超时?

//考虑到以下的情形：并不是每次都拿最大的最好，
//例如对于12: (size): 9+1+1+1 > 4+4+4

//注意到以下的情形：对于某个n，他一定是一个比它小的n组成数字加上某个平方数
//0：default
//1：de + ->1
//2：1 + ->1
//3：2 + ->1
//4：de + ->4

//n： min(n-1, n-4, n-9, ...) + 1  ???

class Solution {
public:
	int numSquares(int n) {
		//DP, O(n*sqrt(n))

		vector<int> dp(n + 1, 0);

		for (int i = 1; i <= n; ++i)
		{
			int temp = INT_MAX;
			for (int j = 1; j <= (int)(sqrt(i));++j)
			{
				temp = min(dp[i - j * j], temp);
			}
			dp[i] = temp + 1;
		}
		return dp[n];
	}
};
