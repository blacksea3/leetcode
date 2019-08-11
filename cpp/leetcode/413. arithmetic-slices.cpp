#include "public.h"

//8ms, 49.89%
//一遍扫描

class Solution {
private:
	//n不会太大
	int fromone_to_n_sum(int n)
	{
		return (1 + n)*n / 2;
	}

public:
	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.size() == 0) return 0;
		int leftloc = 0;
		int res = 0;

		while (leftloc < (int)A.size() - 2)
		{
			if (A[leftloc] + A[leftloc + 2] == 2 * A[leftloc + 1])
			{
				int rightloc = leftloc + 2;
				while (rightloc < A.size() && A[rightloc] - A[rightloc - 1] == A[leftloc + 1] - A[leftloc]) rightloc++;
				res += fromone_to_n_sum(rightloc - leftloc - 2);
				leftloc = rightloc - 1;
			}
			else leftloc++;
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = { 1,2,3,4 };
	cout << s->numberOfArithmeticSlices(A);
	return 0;
}
*/
