#include "public.h"

//4ms, 99.14%
//��̬�滮
//dp[i][j]��ʾS��ǰi���ַ�������T��ǰj���ַ� �� �����еĸ���
//������ 123546 ��  125 ��Ϊ 12354��125��1, 6!=5 ���� 123546 ��  125��1
//�� 123545 ��  125 ��Ϊ 12354��125��1, 6!=5 ���� 123545 ��  125��12354��125(�������5��ʹ��),����12354��12(�������5ʹ��)
//Ӧ���ȸ�j����,�����t�ĳ���
//Ȼ���i����,�����s�ĳ���
//����t��s�е��������Ϊ��1
//����t��s�յ��������Ϊ��0,�Լ�һЩt��s�����������

class Solution {
public:
	int numDistinct(string s, string t) {
		size_t ts = t.size();
		size_t ss = s.size();

		vector<vector<unsigned int>> dp(ts + 1, vector<unsigned int>(ss + 1, 0));

		for (size_t i = 0; i <= ss; i++) dp[0][i] = 1;
			
		for (size_t j = 1; j <= ts; j++)
			for (size_t i = 1; i <= ss; i++)
				if (s[i - 1] == t[j - 1])
					//�����int, ��overflow?!?!?!?
					//������Ŀ��˼,����overflow,���Բ����ܳ�Ϊ���!
					dp[j][i] = dp[j][i - 1] + dp[j - 1][i - 1];
				else
					dp[j][i] = dp[j][i - 1];

		return dp[t.size()][s.size()];
	}
};
