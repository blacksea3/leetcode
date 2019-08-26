#include "public.h"

//8ms, 43.28%
//dp
//����Ҫ��, ֻҪ����һ����С��i������jת���õ�, ��dp[i]=false, ��dp[j] = true
//����������dp[j]=false

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

//���߸��򵥵� return N%2==0, ������Ϊ���������������ô����, ����������ż��; �����ż��, ֻҪѡ��x=1ʹ����������Ϳ�����
//��������˿�ذ�