#include "public.h"

//204ms, 8.00%
//dp[i][j]: i��j����, ������ֵ�������ĳ���, ��������չ
//��ʼ��: dp[i][i] = 1,
//��չ: dp[i][i+len-1](len >= 2) : ��Ϊ����չ������չ: ��������dp[j][k], ����j>i���� k<i+len-1, ���ߵ��ڱ߽�,
//  �����е�A[i]ͬʱ<=A[j] ��A[i+len-1]>=A[k] ��ô��¼��ǰ���ܳ���=dp[j][k]+1,  
//  ��������������dp[i][i+len-1] = max��ǰ���ܳ���, �ر�ע�⼫�п��ܵ�ǰ���ܳ��ȴ�δ����¼, ��ô��ȡ����Ĭ��ֵINT_MIN:)

//�����ÿ�μ�¼��ǰ���ܳ��ȵ�ʱ��, max(res, pre)һ��, ���շ���res����

class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		vector<vector<int>> dp(A[0].size(), vector<int>(A[0].size(), INT_MIN));
		for (int i = 0; i < A[0].size(); ++i)
		{
			dp[i][i] = 1;
		}

		int res = 1;
		for (int len = 2; len <= A[0].size(); ++len)
		{
			for (int i = 0; i <= A[0].size() - len; ++i)
			{
				//cal dp[i][i+len-1]
				int tempmax = INT_MIN;
				//����չ
				for (int j = i + 1; j <= i + len - 1; ++j)
				{
					if (dp[j][i + len - 1] == INT_MIN) continue;
					else
					{
						bool canexpand = true;
						for (int loca = 0; loca < A.size(); ++loca)
						{
							if ((A[loca][i] <= A[loca][j])) continue;
							else
							{
								canexpand = false;
								break;
							}
						}
						if (canexpand)
						{
							tempmax = max(tempmax, 1 + dp[j][i + len - 1]);
						}
					}
				}
				//����չ
				for (int k = i + len - 2; k >= i; --k)
				{
					if (dp[i][k] == INT_MIN) continue;
					else
					{
						bool canexpand = true;
						for (int loca = 0; loca < A.size(); ++loca)
						{
							if ((A[loca][k] <= A[loca][i + len - 1])) continue;
							else
							{
								canexpand = false;
								break;
							}
						}
						if (canexpand)
						{
							tempmax = max(tempmax, 1 + dp[i][k]);
						}
					}
				}
				dp[i][i + len - 1] = tempmax;
				res = max(res, tempmax);
			}
		}
		return A[0].size() - res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<string> A = { "ghi","def","abc" };
	cout << s->minDeletionSize(A);
	vector<string> B = { "babca","bbazb" };
	cout << s->minDeletionSize(B);
	vector<string> C = { "edcba" };
	cout << s->minDeletionSize(C);
	return 0;
}
*/
