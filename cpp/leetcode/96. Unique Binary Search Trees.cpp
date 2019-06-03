#include "public.h"

//4ms, 95.16%

//DP problem, but all history res should be stored

class Solution {
public:
	int numTrees(int n) {
		//a(n=18) = 求和a(i)*a(17-i) i=0至17
		//a(n=0) = 1
		vector<int> numtrees(n + 1, 0);  //numtrees[下标]表示a(n),a(0)=1,a(1)=1

		if (n <= 0) return 0;
		numtrees[0] = 1;
		numtrees[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
				numtrees[i] += numtrees[j] * numtrees[i - 1 - j];
		}
		return numtrees[n];
	}
};