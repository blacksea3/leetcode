#include "public.h"

//80ms, 87.53%
//simple solution

class Solution {
public:
	bool isMonotonic(vector<int>& A) {
		if (A.size() == 1) return true;

		int state = 0; //0:equal, 1:increment, 2:decrement

		for (int i = 0; i < A.size() - 1; ++i)
		{
			if (state == 0)
			{
				if (A[i] > A[i + 1])
				{
					state = 2;
				}
				else if (A[i] < A[i + 1])
				{
					state = 1;
				}
			}
			else if (state == 1)
			{
				if (A[i] > A[i + 1])
				{
					return false;
				}
			}
			else
			{
				if (A[i] < A[i + 1])
				{
					return false;
				}
			}
		}
		return true;
	}
};
