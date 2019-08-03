#include "public.h"

//1000ms, 30.30%
//����B�е�Ԫ��, ������ѡ: ��A������С�ı������Ԫ��, ���û�оͷ���С��

class Solution {
public:
	vector<int> advantageCount(vector<int>& A, vector<int>& B) {
		vector<int> res(A.size(), 0);

		sort(A.begin(), A.end());

		for (int i = 0; i < B.size(); ++i)
		{
			vector<int>::iterator iter = upper_bound(A.begin(), A.end(), B[i]);
			if (iter == A.end())
			{
				res[i] = A[0];
				A.erase(A.begin());
			}
			else
			{
				res[i] = *iter;
				A.erase(iter);
			}
		}
		return res;
	}
};
