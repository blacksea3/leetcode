#include "public.h"

//1000ms, 30.30%
//对于B中的元素, 这样挑选: 在A中找最小的比它大的元素, 如果没有就放最小的

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
