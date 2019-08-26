#include "public.h"

//92ms, 87.07%
//̰��
//����С�Ŀ�ʼ��, ʵ���Ͻ�����Ҫ���һ����С�ĺ�, ���������ֵ����ͬ, ���Ҷ�Ӧλ�ö�>=A

class Solution {
public:
	int minIncrementForUnique(vector<int>& A) {
		if (A.empty()) return 0;
		sort(A.begin(), A.end());
		int old = accumulate(A.begin(), A.end(), 0);

		int oldval = A[0];
		int loc = 1;
		while (loc < A.size())
		{
			if ((oldval + 1) > A[loc])
			{
				A[loc] = oldval + 1;
				oldval++;
			}
			else
			{
				oldval = A[loc];
			}
			loc++;
		}

		int ne = accumulate(A.begin(), A.end(), 0);
		return ne - old;
	}
};
