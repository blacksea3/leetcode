#include "public.h"

//8ms, 71.43%
/*
�������Ӧ�ÿ����뵽�Ľⷨ���ǽ����Եļ��϶��ҳ�����Ȼ�����Щ��������ͬԪ�ص�λ�ñȽϣ����λ��<k����ô���޳������ʣ�µľ���������Ҫ�Ľ⡣���ֱ����ⷨ˼·�ܼ򵥣�����ʵ�ʲ��������������ף������ٶ�Ҳ������

����������ͨ����̬�滮�ķ�����������Ƕ��庯��f(n,l,k)��ʾn�׸����l��λ�ã���ͬ��ļ������k����ô�����Ƕ��ڵ�l��λ����˵ֻ���������

֮ǰû����ͬ�ĸ裬Ҳ����˵n-1�׸������ǰ��l-1��λ�ã���f(n-1,l-1,k)
֮ǰ����ͬ�ĸ裬Ҳ����˵n�׸������ǰ��l-1��λ�ã���f(n,l-1,k)
���ڵ�һ���������Ϊ��n�׸裬���Ի����n�Ρ������ڵڶ��������������ͬ�ĸ費�ܼ��k�����Ի����n-k�Σ���ô

f(n,l,k)=f(n-1,l-1,k)*n+f(n,l-1,k)*(n-k)
�������ǿ��Ǳ߽���������n==lʱ����Ϊȫ���У�Ҳ����n!�֣���i<=K��ʱ�򣬽ⲻ���ڣ��ܺ���⣻��n==K+1ʱ��Ҳ��ȫ���У���Ϊ��ʱ���һ�׸��͵�һ�׸���ͬ��
---------------------
���ߣ�coordinate_blog
��Դ��CSDN
ԭ�ģ�https://blog.csdn.net/qq_17550379/article/details/82992083
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�
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
