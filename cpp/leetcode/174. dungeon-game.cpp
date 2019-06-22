#include "public.h"

//DP problem, 8ms, 94.18%
//dp[i][j]:��i,j�������½ǵ���ͳ�ʼ����ָ��
//�����½������ϽǸ���
//���½�ֵ��ʼ����������1����ȡ����1
//����λ�ø���ֵ���ٸ�����
//dp[i][n - 1] = (dungeon[i][n - 1] >= dp[i + 1][n - 1]) ? 1 : (dp[i + 1][n - 1] - dungeon[i][n - 1]);
//����ʱ���ж������λ�ã�������͵�Ҫ��Ѫ��Ч����

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		//����dungeon��Ϊ��
		int m = dungeon.size();     //row
		int n = dungeon[0].size();  //column

		vector<vector<int>> dp(m, vector<int>(n, 0));

		dp[m - 1][n - 1] = (dungeon[m - 1][n - 1] > 0) ? 1 : -1 * dungeon[m - 1][n - 1] + 1;
		for (int i = m - 2; i >= 0; i--)
			dp[i][n - 1] = (dungeon[i][n - 1] >= dp[i + 1][n - 1]) ? 1 : (dp[i + 1][n - 1] - dungeon[i][n - 1]);
		for (int j = n - 2; j >= 0; j--)
			dp[m - 1][j] = (dungeon[m - 1][j] >= dp[m - 1][j + 1]) ? 1 : (dp[m - 1][j + 1] - dungeon[m - 1][j]);

		for (int i = m - 2; i >= 0; i--)
		{
			for (int j = n - 2; j >= 0; j--)
			{
				dp[i][j] = min((dungeon[i][j] >= dp[i + 1][j]) ? 1 : (dp[i + 1][j] - dungeon[i][j]),
					(dungeon[i][j] >= dp[i][j + 1]) ? 1 : (dp[i][j + 1] - dungeon[i][j])
				);
			}
		}

		return dp[0][0];

	}
};
