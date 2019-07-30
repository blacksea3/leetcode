#include "public.h"

//8ms, 71.43%
/*
大家首先应该可以想到的解法就是将所以的集合都找出来，然后对这些集合中相同元素的位置比较，如果位置<k，那么就剔除，最后剩下的就是我们需要的解。这种暴力解法思路很简单，但是实际操作起来并不容易，而且速度也很慢。

这个问题可以通过动态规划的方法解决。我们定义函数f(n,l,k)表示n首歌填充l个位置，相同歌的间隔超过k。那么，我们对于第l个位置来说只有两种情况

之前没有相同的歌，也就是说n-1首歌填充了前面l-1个位置，即f(n-1,l-1,k)
之前有相同的歌，也就是说n首歌填充了前面l-1个位置，即f(n,l-1,k)
对于第一种情况，因为有n首歌，所以会出现n次。而对于第二种情况，由于相同的歌不能间隔k，所以会出现n-k次，那么

f(n,l,k)=f(n-1,l-1,k)*n+f(n,l-1,k)*(n-k)
接着我们考虑边界条件：当n==l时，即为全排列，也就是n!种；当i<=K的时候，解不存在，很好理解；当n==K+1时，也是全排列，因为此时最后一首歌会和第一首歌相同。
---------------------
作者：coordinate_blog
来源：CSDN
原文：https://blog.csdn.net/qq_17550379/article/details/82992083
版权声明：本文为博主原创文章，转载请附上博文链接！
*/

class Solution {
private:
	int MOD = 1000000007;
	int factorial(int n)
	{
		long long result = 1;
		while (n > 1)
		{
			result *= n;
			result %= MOD;
			n -= 1;
		}
		return result;
	}
public:
	int numMusicPlaylists(int N, int L, int K) {
		vector<vector<int>> dp(N + 1, vector<int>(L + 1, 0));

		for (int i = K + 1; i <= N; ++i)
		{
			for (int j = i; j <= L; ++j)
			{
				if ((i == j) || (i == (K + 1)))
				{
					dp[i][j] = factorial(i);
				}
				else
				{
					long long bignum = (long long)dp[i - 1][j - 1] * i + (long long)dp[i][j - 1] * (i - K);
					bignum %= MOD;
					dp[i][j] = bignum;
				}
			}
		}
		return dp[N][L];
	}
};
