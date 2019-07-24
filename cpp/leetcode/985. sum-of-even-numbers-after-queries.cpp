#include "public.h"

//200ms, 87.67%
//Ä£Äâ

class Solution {
public:
	vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
		int sum = 0;
		for (auto& a : A) if (a % 2 == 0) sum += a;

		vector<int> res(queries.size(), 0);

		for (int i = 0; i < queries.size(); ++i)
		{
			int loc = queries[i][1];
			int val = queries[i][0];
			if ((val % 2 == 0) && (A[loc] % 2 == 0))
			{
				sum += val;
				A[loc] += val;
			}
			else if ((val % 2 != 0) && (A[loc] % 2 == 0))
			{
				sum -= A[loc];
				A[loc] += val;
			}
			else if ((val % 2 == 0) && (A[loc] % 2 != 0))
			{
				A[loc] += val;
			}
			else
			{
				sum += A[loc] + val;
				A[loc] += val;
			}
			res[i] = sum;
		}

		return res;
	}
};
