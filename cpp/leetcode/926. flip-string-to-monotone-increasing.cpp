#include "public.h"

//44ms, 6.85%
//ͳ����iλ�ÿ�ʼ�����Լ����ú���ȫ��1, Ӧ����ת��0����, ��ô�������ʵ���ܷ�ת��������iλ��֮ǰ��1����+iλ��֮���0����
//����Ӧ������������������
//����һ��dp[i][0]��dp[i][1]��ʾ0-i��1�����Լ�i-����0����, �����������Сֵ����, ע���±�0, ͳ��1, �±�1, ͳ��0, ���Ƿ���

class Solution {
public:
	int minFlipsMonoIncr(string S) {
		vector<vector<int>> dp(S.size(), vector<int>(2, 0));
		if (S[0] == '1') dp[0][0] = 1;
		for (int i = 1; i < S.size(); ++i)
		{
			if (S[i] == '1') dp[i][0] = dp[i - 1][0] + 1;
			else dp[i][0] = dp[i - 1][0];
		}
		if (S[S.size() - 1] == '0') dp[S.size() - 1][1] = 1;
		for (int i = S.size() - 2; i >= 0; --i)
		{
			if (S[i] == '0') dp[i][1] = dp[i + 1][1] + 1;
			else dp[i][1] = dp[i + 1][1];
		}

		int res = INT_MAX;
		for (int i = 1; i < S.size(); ++i)
			res = min(res, dp[i-1][0] + dp[i][1]);
		res = min(res, dp[S.size() - 1][0]);
		res = min(res, dp[0][1]);
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//cout << s->minFlipsMonoIncr("00110");
	//cout << s->minFlipsMonoIncr("0101100011");
	cout << s->minFlipsMonoIncr("00000000000000000000000000000000000000000000000000000000000000000010100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
	return 0;
}
*/
