#include <iostream>
#include <vector>
#include <fstream>

//DP问题
using namespace std;

/*
int main()
{
	//std::ifstream cin;  //覆盖全局std:cin
	//cin.open("D:\\PC\\GitFiles\\leetcode\\cpp\\newcodedata\\yinbihuafen.txt", std::ios::in);
	//if (!cin.is_open())
	//{
	//	throw std::exception("FATAL ERROR");
	//}
	//else
	{
		long long MOD = 1000000007;
		long long n;
		cin >> n;
		std::vector<std::vector<long long>> dp(n+1, std::vector<long long>(5, 0)); //最大的是0, 1, 2, 5, 10
		dp[0][0] = 1;

		for (int i = 1; i <= n; ++i)
		{
			dp[i][1] += dp[i - 1][0];
			dp[i][1] += dp[i - 1][1];
			dp[i][1] %= MOD;
			if (i >= 2)
			{
				dp[i][2] += dp[i - 2][0];
				dp[i][2] += dp[i - 2][1];
				dp[i][2] += dp[i - 2][2];
				dp[i][2] %= MOD;
			}
			if (i >= 5)
			{
				dp[i][3] += dp[i - 5][0];
				dp[i][3] += dp[i - 5][1];
				dp[i][3] += dp[i - 5][2];
				dp[i][3] += dp[i - 5][3];
				dp[i][3] %= MOD;
			}
			if (i >= 10)
			{
				dp[i][4] += dp[i - 10][0];
				dp[i][4] += dp[i - 10][1];
				dp[i][4] += dp[i - 10][2];
				dp[i][4] += dp[i - 10][3];
				dp[i][4] += dp[i - 10][4];
				dp[i][4] %= MOD;
			}
		}
		std::cout << ((dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4]) % MOD) << std::endl;
	}
}
*/