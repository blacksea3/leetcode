#include "public.h"

//
//��������
//�����޸�С�ĸ���, ����޸Ĺ���, ��K�Ƿ���ż��, ���򲻹�, �������޸Ļ�һ������(�����)

class Solution {
public:
	int largestSumAfterKNegations(vector<int>& A, int K) {
		sort(A.begin(), A.end(), less<int>());

		for (int i = 0; i < K; ++i)
		{
			if (A[i] <= 0) A[i] = -1 * A[i];
			else if ((K - i) % 2 == 0) return accumulate(A.begin(), A.end(), 0);
			else
			{
				if (i > 0)
				{
					if (i < A.size() - 1 && A[i - 1] > A[i])
						A[i] = -1 * A[i];
					else A[i - 1] = -1 * A[i - 1];
				}
				else A[i] = -1 * A[i];
				return accumulate(A.begin(), A.end(), 0);
			}
		}

		return accumulate(A.begin(), A.end(), 0);
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<int> A = {3, -1, 0, 2};
	//cout << s->largestSumAfterKNegations(A, 3);
	//vector<int> A = { 5, 6, 9, -3, 3 };
	//cout << s->largestSumAfterKNegations(A, 2);
	
	vector<int> A = { 8, -7, -3, -9, 1, 9, -6, -9, 3 };
	cout << s->largestSumAfterKNegations(A, 8);
	
	return 0;
}
*/
