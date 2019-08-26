#include "public.h"

//8ms, 66.15%
//大模拟, 暴力

class Solution {
public:
	double new21Game(int N, int K, int W) {
		if (K == 0) return 1.0;
		if (K == 1) return min(N, W) / (double)W;
		vector<double> dp(N + 1, 0);       //概率
		vector<double> sumArr(N + 1, 0);   //前i项概率和
		dp[0] = 1.0;

		for (int i = 1; i <= N; ++i)
		{
			int left = max(0, i - W), right = min(i - 1, K - 1);
			double p = (sumArr[right] - sumArr[left] + dp[left]) / W;
			dp[i] = p;
			sumArr[i] = sumArr[i - 1] + p;
		}

		return sumArr[N] - sumArr[K - 1];
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->new21Game(6, 1, 10);
	//cout << s->new21Game(21, 17, 10);
	return 0;
}
