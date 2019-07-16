#include "public.h"

//292ms, 6.12%
//找到第一个数字下降的位置(例如A[i] > A[i + 1])
//如果没有, 那么不存在
//如果有, 找出后续的数字中比A[i]大的最小数字, 然后交换他们, 再给i+1开始的数字升序排序

class Solution {
public:
	vector<int> prevPermOpt1(vector<int>& A) {
		bool isalldecrement_reverse = true;
		int targetloc = 0;
		for (int i = A.size() - 2; i >= 0; --i)
			if (A[i] > A[i + 1])
			{
				targetloc = i;
				isalldecrement_reverse = false;
				break;
			}

		if (isalldecrement_reverse) return A;
		else
		{
			//brute force
			bool isfind_loc = false;
			for (int j = targetloc + 2; j < A.size(); ++j)
				if (A[j] >= A[targetloc])
				{
					//swap: j-1 and targetloc
					int temp = A[targetloc];
					A[targetloc] = A[j - 1];
					A[j - 1] = temp;
					isfind_loc = true;
					break;
				}
			if (!isfind_loc)
			{
				//swap: last and targetloc
				int temp = A[targetloc];
				A[targetloc] = A[A.size() - 1];
				A[A.size() - 1] = temp;
			}
			return A;
		}
	}
};

