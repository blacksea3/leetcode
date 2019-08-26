#include "public.h"

//16ms, 50.00%
//����:��������
//ģ��, �Ӻ�ǰ����, �������η�ת

class Solution {
public:
	vector<int> pancakeSort(vector<int>& A) {
		int loc = A.size() - 1;

		vector<int> res;
		while (loc < A.size())
		{
			int maxloc = -1;
			int maxval = INT_MIN;
			for (int i = loc; i >= 0; --i)
			{
				if (A[i] > maxval)
				{
					maxval = A[i];
					maxloc = i;
				}
			}
			if (maxloc == loc) loc--;
			else
			{
				//�ȷ�ת[0,maxloc]�ٷ�ת[0,loc]
				for (int i = 0; i <= maxloc / 2; ++i)
				{
					swap(A[i], A[maxloc - i]);
				}
				res.push_back(maxloc + 1);
				for (int i = 0; i <= loc / 2; ++i)
				{
					swap(A[i], A[loc - i]);
				}
				res.push_back(loc + 1);
				loc--;
			}
		}

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = {3,2,4,1};
	auto res = s->pancakeSort(A);
	return 0;
}
*/
