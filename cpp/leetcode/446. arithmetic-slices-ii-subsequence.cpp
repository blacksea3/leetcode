#include "public.h"

//804ms, 85.57%
//����f[i][d]: ��A[i]��β����Ϊd�ĵȲ�����(����>=2)
//��f[i][A[i]-A[j]] = f[j][A[i]-A[j]] + 1, ����f[j][A[i]-A[j]]�ǰ���A[i]�ĳ���>=3�ĵȲ���������, +1�ǵ�ǰA[i]��A[j]���ɵĳ��ȵ���2������
//��ÿ������f[j][A[i]-A[j]]��ͼ���

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int res = 0;
		int ASize = A.size();
		vector<unordered_map<long long, int>> dp(A.size());

		for (int i = 1; i < ASize; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				long long delta = (long long)A[i] - A[j];
				if (dp[j].find(delta) != dp[j].end())
				{
					dp[i][delta] += dp[j][delta];
					res += dp[j][delta];
				}
				dp[i][delta]++;
			}
		}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> A = { 2,2,3,4 };
	cout << s->numberOfArithmeticSlices(A);
	return 0;
}
