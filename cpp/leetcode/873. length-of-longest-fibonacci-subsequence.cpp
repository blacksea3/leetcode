#include "public.h"

//520ms, 19.35%
//ֱ����, ����, �ö�����

class Solution {
public:
	int lenLongestFibSubseq(vector<int>& A) {
		int res = 0;

		for (int first = 0; first < A.size() - 2; ++first)
		{
			for (int second = first + 1; second < A.size() - 1; ++second)
			{
				//�ж��Ƿ��ܹ�����
				int cpf = first;
				int cps = second;
				int prer = 2;
				while (true)
				{
					int third = A[cps] + A[cpf];
					bool tempr = binary_search(A.begin() + cps + 1, A.end(), third);
					if (tempr)
					{
						int n = lower_bound(A.begin() + cps + 1, A.end(), third) - A.begin();
						prer++;
						cpf = cps;
						cps = n;
					}
					else
					{
						break;
					}
				}
				res = max(res, prer);
			}
		}
		return (res == 2) ? 0 : res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = { 1,2,3,4,5,6,7,8 };
	cout << s->lenLongestFibSubseq(A);
	return 0;
}
*/
