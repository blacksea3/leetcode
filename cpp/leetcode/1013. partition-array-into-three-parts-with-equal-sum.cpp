#include "public.h"

//72ms, 73.64%
//先计算总和, 然后朴素方法

class Solution {
public:
	bool canThreePartsEqualSum(vector<int>& A) {
		int sum = accumulate(A.begin(), A.end(), 0);

		if (sum % 3) return false;

		if (sum != 0)
		{
			int presum = 0;
			int loc = 0;
			for (; loc < A.size(); ++loc)
			{
				if (presum == sum / 3) break;
				presum += A[loc];
			}
			if (loc == A.size()) return false;
			presum = 0;
			for (; loc < A.size(); ++loc)
			{
				if (presum == sum / 3) break;
				presum += A[loc];
			}
			if (loc == A.size()) return false;
			presum = 0;
			for (; loc < A.size(); ++loc)
			{
				if (presum == sum / 3) break;
				presum += A[loc];
			}
			return true;
		}
		else
		{
			int presum = A[0];
			int loc = 1;
			for (; loc < A.size(); ++loc)
			{
				if (presum == sum / 3) break;
				presum += A[loc];
			}
			if (loc == A.size()) return false;
			presum = A[loc++];
			for (; loc < A.size(); ++loc)
			{
				if (presum == sum / 3) break;
				presum += A[loc];
			}
			if (loc == A.size()) return false;
			presum = A[loc++];
			for (; loc < A.size(); ++loc)
			{
				if (presum == sum / 3) break;
				presum += A[loc];
			}
			return true;
		}
	}
};
