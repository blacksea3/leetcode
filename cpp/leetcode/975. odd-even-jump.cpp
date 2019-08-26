#include "public.h"

//904ms, 6.38%
//Ӧ������������
//����������dpֵ: dp[i][0]��ʾ��i��ʼ�������������Ե��յ�, dp[i][1]��ʾ��i��ʼ����ż�������Ե��յ�
//�ڵ��������;�м�¼unordered_map<int, int>: ��val, index, �ټ�¼һ��vector<int>��val����, ��lower_bound���ҺͲ���ֵ
//dp[i][0]:����С��val>=A[i], Ȼ��dp[i][0]=dp[index][1]
//dp[i][1]:����С��val<=A[i], Ȼ��dp[i][1]=dp[index][0]
//��ʼ��dp[A.size()-1][0]=true, dp[A.size()-1][1]=true

class Solution {
public:
	int oddEvenJumps(vector<int>& A) {
		vector<vector<bool>> dp(A.size(), vector<bool>(2, false));
		dp[A.size() - 1][0] = true;
		dp[A.size() - 1][1] = true;

		unordered_map<int, int> ps;
		vector<int> p_vals;

		ps[A[A.size() - 1]] = A.size() - 1;
		p_vals.push_back(A[A.size() - 1]);

		for (int i = A.size() - 2; i >= 0; --i)
		{
			vector<int>::iterator piter = lower_bound(p_vals.begin(), p_vals.end(), A[i]);
			if (piter == p_vals.end())
				dp[i][0] = false;
			else
				dp[i][0] = dp[ps[*piter]][1];

			if (piter != p_vals.end() && *piter == A[i])
				dp[i][1] = dp[ps[*piter]][0];
			else
			{
				if (piter == p_vals.begin())
					dp[i][1] = false;
				else
					dp[i][1] = dp[ps[*(piter - 1)]][0];
			}

			if (piter != p_vals.end() && *piter == A[i])
			{
				ps[A[i]] = i;
			}
			else
			{
				ps[A[i]] = i;
				p_vals.insert(piter, A[i]);
			}
		}

		int res = 0;
		for (int i = 0; i < dp.size(); ++i)
		{
			if (dp[i][0]) res++;
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = { 5, 1, 3, 4, 2 };
	auto res = s->oddEvenJumps(A);
	return 0;
}
*/
