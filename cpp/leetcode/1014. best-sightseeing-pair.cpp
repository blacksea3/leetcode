#include "public.h"

//72ms, 77.54%
//�ȶ�����A[i]-i
//Ȼ������dp����: dp[i]�Ǵ����ұ������������ֵ
//Ȼ�����߿�ʼ, ÿ�ζ����ұߵ�һ�����ֵ���, ���Ҽ������ƫ����

class Solution {
public:
	int maxScoreSightseeingPair(vector<int>& A) {
		for (int i = 0; i < A.size(); ++i)
			A[i] -= i;

		int premax = INT_MIN;
		vector<int> dp(A.size());
		for (int i = A.size() - 1; i >= 0; --i)
		{
			premax = max(premax, A[i]);
			dp[i] = premax;
		}

		//һ��ɨ��
		int res = 0;

		for (int i = 0; i < A.size() - 1; ++i)
		{
			res = max(res, A[i] + dp[i + 1] + 2 * i);
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = { 1,3,5 };
	auto res = s->maxScoreSightseeingPair(A);
	return 0;
}
*/
