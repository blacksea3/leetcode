#include "public.h"

//176ms, 15.91%
//simple solution
//“ª¬÷…®√Ë

class Solution {
public:
	int maxTurbulenceSize(vector<int>& A) {
		int res = 1;
		int premax = 1;

		int loc = 0;
		while (loc < A.size() - 1)
		{
			if (A[loc] > A[loc + 1]) //ÕªΩ¯…®√Ë
			{
				premax++;
				bool rev = false;
				loc++;
				while (loc < A.size() - 1)
				{
					if (rev)
					{
						if (A[loc] > A[loc + 1])
						{
							premax++;
							rev = false;
							loc++;
						}
						else break;
					}
					else
					{
						if (A[loc] < A[loc + 1])
						{
							premax++;
							rev = true;
							loc++;
						}
						else break;
					}
				}
				res = max(res, premax);
				premax = 1;
			}
			else if (A[loc] < A[loc + 1]) //ÕªΩ¯…®√Ë
			{
				premax++;
				bool rev = true;
				loc++;
				while (loc < A.size() - 1)
				{
					if (rev)
					{
						if (A[loc] > A[loc + 1])
						{
							premax++;
							rev = false;
							loc++;
						}
						else break;
					}
					else
					{
						if (A[loc] < A[loc + 1])
						{
							premax++;
							rev = true;
							loc++;
						}
						else break;
					}
				}
				res = max(res, premax);
				premax = 1;
			}
			else
			{
				loc++;
			}
		}
		return res;
	}
};

