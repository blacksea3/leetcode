#include "public.h"

//44ms, 16.28%
//三维dp
//dp[i][j][k]:将下标i-j分成k份: dp[i][j][k] = min(dp[i][j][k], dp[i][mid][k-1] + dp[mid+1][j][1]);
//注意:此处的j和mid应当相对i跳着K-1选取
//dp[i][j][1] = mid(dp[i][j][1], dp[i][j][K] + sum(i, j));

//注意:在不可能出现的长度: 例如K = 3, len = 2时更新dp[st][en][1]时是无效的, 但是代码不影响

class Solution {
public:
	int mergeStones(vector<int>& stones, int K) {
		int l = stones.size();
		if (l == 1) return 0;
		if ((l - 1) % (K - 1) != 0) return -1;

		vector<vector<vector<int>>> dp(l, vector<vector<int>>(l, vector<int>(K + 1, 10000)));  //这里要设置某个中间值为默认最大值

		for (int i = 0; i < l; ++i) dp[i][i][1] = 0;

		for (int len = 2; len <= l; ++len)
		{
			for (int st = 0; st <= l - len; ++st)
			{
				int en = st + len - 1;
				for (int mid = st; mid < en; mid++)
				{
					for (int k = 2; k <= K; ++k)
					{
						dp[st][en][k] = min(dp[st][en][k], dp[st][mid][k - 1] + dp[mid + 1][en][1]);
					}
				}
				dp[st][en][1] = min(dp[st][en][1], dp[st][en][K] + accumulate(stones.begin() + st, stones.begin() + en + 1, 0));
			}
		}
		return dp[0][l - 1][1];
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> stones = { 3,5,1,2,6 };
	auto res = s->mergeStones(stones, 3);
	//vector<int> stones = {3,2,4,1};
	//auto res = s->mergeStones(stones, 2);
	return 0;
}
