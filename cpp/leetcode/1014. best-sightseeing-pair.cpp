#include "public.h"

//72ms, 77.54%
//先对所有A[i]-i
//然后设置dp满足: dp[i]是从最右边往左数的最大值
//然后从左边开始, 每次都和右边的一个最大值相加, 并且加上左边偏移量

class Solution {
public:
	int maxScoreSightseeingPair(vector<int>& A) {
		for (int i = 0; i < A.size(); ++i)
			A[i] -= i;

		int premax = INT_MIN;
		vector<int> dp(A.size());
		for (int i = A.size() - 1; i >= 0; --i)
		{
			premax = max(premax, A[i]);
			dp[i] = premax;
		}

		//一遍扫描
		int res = 0;

		for (int i = 0; i < A.size() - 1; ++i)
		{
			res = max(res, A[i] + dp[i + 1] + 2 * i);
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = { 1,3,5 };
	auto res = s->maxScoreSightseeingPair(A);
	return 0;
}
*/
