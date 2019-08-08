#include "public.h"

//8ms, 78.05%
//复杂dp
//参考
//https://blog.csdn.net/lemonmillie/article/details/88926645
//如果不是刚好到位置, 那么就分为先行驶足够长距离但不超过当前t, 然后枚举返回距离, 现在我们可以根据剩余应该行驶距离得出此次dp的值
//又或者, 我们可以先行驶超过t的距离, 然后我们可以根据应该的反向行驶距离得出此次dp的值
//这题目的边界条件实在是太复杂了

class Solution {
public:
	int dp[10001];

	int racecar(int t) {
		if (dp[t] > 0) return dp[t];
		int n = floor(log2(t)) + 1, res;
		if (1 << n == t + 1) dp[t] = n;
		else {
			dp[t] = racecar((1 << n) - 1 - t) + n + 1;
			for (int m = 0; m < n - 1; ++m)
				dp[t] = min(dp[t], racecar(t - (1 << (n - 1)) + (1 << m)) + n + m + 1);
		}
		return dp[t];
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->racecar(7) << endl;
	//cout << s->racecar(3) << endl;
	//cout << s->racecar(6) << endl;
	//cout << s->racecar(5) << endl;
	return 0;
}
