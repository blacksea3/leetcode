#include "public.h"

//
//dp[i+1] = 6*dp[i] - SUM(dp[i-rollMax[i]])

class Solution {
public:
	int dieSimulator(int n, vector<int>& rollMax) {
		vector<long long> dp(n, 0);  //dp[i]:��ɫ�Ӵ���Ϊi+1��ʱ��������
		long long MOD = 1000000007;

		dp[0] = 6;

		for (int time = 1; time < n; ++time)
		{
			long long next = 6 * dp[time - 1];

			for (auto& dup : rollMax)
			{
				//��ɫ��time+1������׼ֵ 6*dp[time-1]
				//����ǰ���������dup����ǰֵ���� dp[time-1-dup]����±��Ǹ�һ��ôdp����1   -dp[time-1-dup]
				//Ȼ��dp[time-1-dup-1]ָ���ǲ���ǰ�����, ��һ�β��������ֵ   +dp[time-1-dup-1]
				//���Ծ���: 6*dp[time-1] - dp[time-1-dup] + dp[time-1-dup-1] - dp[time-1-dup-1-dup] ...
				bool isMinus = true;
				int base = (time - dup - 1);
				int preIndex = base;

				while (preIndex >= -1)
				{
					if (isMinus)
					{
						if (preIndex == -1)
						{
							if (next == 0)
								next = MOD;
							next--;
						}
						else
						{
							if (next >= dp[preIndex])
							{
								next -= dp[preIndex];
							}
							else
							{
								next += MOD;
								next -= dp[preIndex];
							}
						}
						isMinus = false;
						preIndex--;
					}
					else
					{
						if (preIndex == -1) next++;
						else
						{
							next += dp[preIndex];
						}
						isMinus = true;
						preIndex -= dup;
					}
				}
			}
			dp[time] = next % MOD;
		}

		return dp[n - 1];
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> rollMax = { 1,1,2,2,2,3 };
	cout << s->dieSimulator(2, rollMax) << endl;
	vector<int> rollMax2 = { 1,1,1,1,1,1 };
	cout << s->dieSimulator(2, rollMax2) << endl;
	vector<int> rollMax3 = { 1,1,1,2,2,3 };
	cout << s->dieSimulator(3, rollMax3) << endl;
	vector<int> rollMax4 = { 2,1,1,3,3,2 };
	cout << s->dieSimulator(4, rollMax4) << endl;
	vector<int> rollMax5 = { 2,3,1,2,1,2 };
	cout << s->dieSimulator(30, rollMax5) << endl;
	return 0;
}
*/