#include "public.h"

//8ms, 43.28%
//dp
//按照要求, 只要存在一个更小的i可以由j转换得到, 且dp[i]=false, 则dp[j] = true
//都不存在则dp[j]=false

class Solution {
public:
	bool divisorGame(int N) {
		vector<bool> dp(N + 1, false);

		for (int i = 2; i <= N; ++i)
		{
			for (int j = 1; j <= i / 2; ++j)
			{
				if (i%j == 0 && !dp[i - j])
				{
					dp[i] = true;
					break;
				}
			}
		}
		return dp[N];
	}
};

//或者更简单的 return N%2==0, 这是因为如果是奇数无论怎么操作, 接下来都是偶数; 如果是偶数, 只要选择x=1使他变成奇数就可以了
//奇数爱丽丝必败