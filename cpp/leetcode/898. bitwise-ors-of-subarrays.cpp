#include "public.h"

//948ms, 66.92%
//±©Á¦, O(n^2)

class Solution {
public:
	int subarrayBitwiseORs(vector<int>& A) {
		unsigned int i, j, bitwisesum, max, length = (unsigned int)A.size();
		unordered_set<unsigned int> nums;
		max = 0;
		for (i = 0; i < length; i++)
		{
			max |= A[i];
		}
		nums.insert(max);

		for (i = 0; i < length; i++)
		{
			bitwisesum = 0;
			for (j = i; j < length; j++)
			{
				bitwisesum |= A[j];
				if (bitwisesum == max)
					break;
				nums.insert(bitwisesum);
			}
		}
		return nums.size();
	}
};
