#include "include.h"

#ifdef LEETCODE_171_180
#include "public.h"
#include "leetcode.h"

int Solution::titleToNumber(string s)
{
	int res = 0;
	for (auto is : s)
	{
		res *= 26;
		res += is - 'A' + 1;
	}
	return res;
}

int Solution::trailingZeroes(int n)
{
	//ʶ��5/5ƽ��/5���η�������
	//��ֻ��Ҫ�����n/5 ; n/25....��ֵ�Ϳ�

	int iter_five = 5;
	int res = 0;
	while (n > iter_five)
	{
		res += n / iter_five;
		if (iter_five > 1000000000) break;  //��ֹ���
		iter_five *= 5;
	}
	return res;
}

int Solution::calculateMinimumHP(vector<vector<int>>& dungeon)
{
	//dp[i][j]:��i,j�������½ǵ���ͳ�ʼ����ָ��

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


#else
#endif
