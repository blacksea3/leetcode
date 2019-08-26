#include "public.h"

//60ms, 46.81%
//dp[i][p]: ȡǰi��rods��ʱ��, �߶Ȳ�Ϊp��ʱ��, ��ߵĹ����
//��ʼ�����е�dp����INT_MIN, dp[0][0] = 0;
//��rods����, (0<=i<rods.size())
//���������������: �µ�rod����, ��ôdp[i][p] = dp[i-1][p], 0<=p<=5000
//�µ�rod�ӵ�����: dp[i][j+h] = max(dp[i][j+h] , dp[i][j] + h)
//�µ�rod�ӵ��̶�: dp[i][abs(j-h)] = max( dp[i][abs(j-h)] , dp[i-1][j] + min(j, h) )

//������dp[rods.size()][0]

class Solution {
public:
	int tallestBillboard(vector<int>& rods) {
		int len = rods.size();
		vector<vector<int>> dp(len + 1, vector<int>(5001, -5001));
		int sum = 0;
		dp[0][0] = 0;
		for (int i = 1; i <= len; i++) {
			sum += rods[i - 1];
			for (int j = 0; j <= sum; j++) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j]);
				if (j + rods[i - 1] <= sum)
					dp[i][j + rods[i - 1]] = max(dp[i - 1][j], dp[i][j + rods[i - 1]]);

				dp[i][abs(j - rods[i - 1])] = max(dp[i][abs(j - rods[i - 1])], dp[i - 1][j] + min(j, rods[i - 1]));
			}
		}
		return dp[len][0];
	}
};
