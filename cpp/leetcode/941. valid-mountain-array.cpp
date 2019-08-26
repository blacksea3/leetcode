#include "public.h"

//52ms, 32.37%
//Ä£Äâ

class Solution {
public:
	bool validMountainArray(vector<int>& A) {
		if (A.empty()) return false;

		int state = 0;
		for (int i = 0; i < A.size() - 1; ++i)
		{
			if (state == 0)
			{
				if (A[i] > A[i + 1]) return false;
				else if (A[i] < A[i + 1])
				{
					state = 1;
				}
				else return false;
			}
			else if (state == 1)
			{
				if (A[i] > A[i + 1])
				{
					state = 2;
				}
				else if (A[i] < A[i + 1])
				{
					;
				}
				else return false;
			}
			else
			{
				if (A[i] > A[i + 1])
				{
					;
				}
				else if (A[i] < A[i + 1])
				{
					return false;
				}
				else return false;
			}
		}
		return (state == 2);
	}
};
