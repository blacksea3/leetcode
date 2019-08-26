#include "public.h"

//12ms, 85.42%
//����n����, �������F(0)
//Ȼ�� F(1) = sum(��ȥ��n����) - (n-1)*��n���� + F(0)
//F(2) = sum(����n-1����) - (n-1)*��n-1���� + F(1)
//...
//F(n-1) = sum(����2����) - (n-1)*��2����

class Solution {
public:
	int maxRotateFunction(vector<int>& A) {
		if (A.empty()) return 0;

		vector<long> cpA(A.size(), 0);

		long rmax = INT_MIN;
		long pre = 0;
		long bias = 0;
		long Asize = A.size();
		for (long i = 0; i < Asize; ++i) cpA[i] = A[i];
		//����F(0)
		for (long i = 1; i < Asize; ++i)
		{
			pre += i * cpA[i];
			bias += cpA[i];
		}
		bias += cpA[0];
		rmax = max(rmax, pre);

		//��������F
		for (long i = Asize - 1; i >= 1; --i)
		{
			long temp = bias - Asize * cpA[i];
			pre += temp;
			rmax = max(rmax, pre);
		}

		return rmax;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 4,3,2,6 };
	auto res = s->maxRotateFunction(nums);
	return 0;
}
*/
