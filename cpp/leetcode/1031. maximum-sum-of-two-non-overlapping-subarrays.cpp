#include "public.h"

//8ms, 98.21%
//O(n) ��������: ��Ȼ����һ���ֽ���: ��A��ֳ�����, ������: Ѱ����������ΪL��M��������
// ���Ұ��: Ѱ����һ����

//����dp[i][0]: ��A[0]-A[i]����L��������������Ԫ�غ�
//dp[i][1]: ��A[0]-A[i]����M��������������Ԫ�غ�
//dp[i][2]: ��A[i]-A[A.size()-1]����L��������������Ԫ�غ�
//dp[i][3]: ��A[i]-A[A.size()-1]����M��������������Ԫ�غ�
//������Χ��Ϊdump: 0

class Solution {
public:
	int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
		//����dp, 4����������, 4�����
		vector<vector<int>> dp(A.size(), vector<int>(4, 0));
		int presum = 0;
		int maxsum;
		for (int i = 0; i < L; ++i)
		{
			presum += A[i];
		}
		maxsum = presum;
		dp[L - 1][0] = maxsum;
		for (int i = L; i < A.size(); ++i)
		{
			presum -= A[i - L];
			presum += A[i];
			maxsum = max(maxsum, presum);
			dp[i][0] = maxsum;
		}

		presum = 0;
		for (int i = 0; i < M; ++i)
		{
			presum += A[i];
		}
		maxsum = presum;
		dp[M - 1][1] = maxsum;
		for (int i = M; i < A.size(); ++i)
		{
			presum -= A[i - M];
			presum += A[i];
			maxsum = max(maxsum, presum);
			dp[i][1] = maxsum;
		}

		presum = 0;
		for (int i = A.size() - 1; i >= A.size() - L; --i)
		{
			presum += A[i];
		}
		maxsum = presum;
		dp[A.size() - L][2] = maxsum;
		for (int i = A.size() - L - 1; i >= 0; --i)
		{
			presum -= A[i + L];
			presum += A[i];
			maxsum = max(maxsum, presum);
			dp[i][2] = maxsum;
		}

		presum = 0;
		for (int i = A.size() - 1; i >= A.size() - M; --i)
		{
			presum += A[i];
		}
		maxsum = presum;
		dp[A.size() - M][3] = maxsum;
		for (int i = A.size() - M - 1; i >= 0; --i)
		{
			presum -= A[i + M];
			presum += A[i];
			maxsum = max(maxsum, presum);
			dp[i][3] = maxsum;
		}

		//�����
		int res = 0;
		//L��M���
		for (int i = L; i <= A.size() - M; ++i)
			res = max(res, dp[i - 1][0] + dp[i][3]);
		//M��L���
		for (int i = M; i <= A.size() - L; ++i)
			res = max(res, dp[i - 1][1] + dp[i][2]);

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = { 0, 6, 5, 2, 2, 5, 1, 9, 4 };
	auto res = s->maxSumTwoNoOverlap(A, 1, 2);
	return 0;
}
*/
