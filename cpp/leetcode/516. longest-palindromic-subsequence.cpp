#include "public.h"

//216ms, 11.49%
//��̬�滮, ��������չ
//����dp[i][j] ��ʾ�±�i��j, ����ұ�
//��ʼ�� dp[i][i] = 1; dp[i][i+1] = 1��2
//������, �Ե�ǰ����, ����=����������2���ڲ�, ����!=����������max(ȥ�����, ȥ���ұ�)
//O(n^2)

class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int sSize = s.size();
		vector<vector<int>> dp(sSize, vector<int>(sSize, 1));

		//init
		for (int index = 0; index < s.size() - 1; ++index)
		{
			if (s[index] == s[index + 1])
			{
				dp[index][index + 1] = 2;
			}
		}

		int res = 1;
		//����
		for (int length = 3; length <= s.size(); ++length)
		{
			for (int start = 0; start <= s.size() - length; ++start)
			{
				int end = start + length - 1;
				if (s[start] == s[end])
				{
					dp[start][end] = 2 + dp[start + 1][end - 1];
					res = max(res, dp[start][end]);
				}
				else
				{
					dp[start][end] = max(dp[start + 1][end], dp[start][end - 1]);
				}
			}
		}
		return res;
	}
};
