#include "public.h"

//88ms, 28.77%
//��������Ҫ����: big < (medium + small)
//����ȡ�����������

class Solution {
public:
	int largestPerimeter(vector<int>& A) {
		sort(A.begin(), A.end(), greater<int>());

		int res = 0;

		for (int i = 0; i < A.size() - 2; ++i)
		{
			if (A[i] < (A[i + 1] + A[i + 2]))
			{
				res = A[i] + A[i + 1] + A[i + 2];
				break;
			}
		}
		return res;
	}
};
