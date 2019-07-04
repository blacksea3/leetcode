#include "public.h"

//4ms, 85.84%
//��ѧ��, DP solution
//dp[i]: i-1λ���ĸ�λ���ֶ���ͬ�����ֵĸ���
//dp[0]: 1
//dp[1]: 9
//����Ϊ����
//dp[2]: 9*dp[1]
//dp[3]: 8*dp[2]
//dp[4]: 7*dp[3]...
//...
//Ȼ�������

class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n >= 10) return 0;
		else
		{
			vector<int> dp(n + 1, 0);
			if (n == 0) return 0;
			else
			{
				dp[1] = 9;
				for (int i = 2; i <= n; ++i)
				{
					dp[n] = (11 - n)*dp[n - 1];
				}

				int res = 0;
				for (int i = 0; i <= n; ++i)
					res += dp[i];
				return res;
			}
		}
	}
};
