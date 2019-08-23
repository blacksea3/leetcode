#include "public.h"

//248ms, 21.24%
//��������
//dp[j][k]: ʹ��j��0, k��1���������
//�ڱ�ֵ: dp[0][0] = 0
//0<=j<=m, 0<=k<=n
//���ַ�������
//  dp[j][k] = max(dp[j][k], dp[j-����][k-����]+1)

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

		dp[0][0] = 0;

		for (auto& str : strs)
		{
			int countOne = 0;
			int countZero = 0;
			for (auto& iter_str : str)
			{
				if (iter_str == '1') countOne++;
				else countZero++;
			}

			for (int iterCountOne = n; iterCountOne >= countOne; iterCountOne--)
			{
				for (int iterCountZero = m; iterCountZero >= countZero; iterCountZero--)
				{
					dp[iterCountZero][iterCountOne] = max(dp[iterCountZero][iterCountOne],
						dp[iterCountZero - countZero][iterCountOne - countOne] + 1);
				}
			}
		}
		return dp[m][n];   //ע��:Ҳ��dp[m][n]���˷Ѷ����m/n��������ֵһ�������������ַ�������(һ������ʹ�������ַ�������ʹ�õ�0��1�ĸ�����dpֵ)
	}
};
