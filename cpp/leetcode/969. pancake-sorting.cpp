#include "public.h"

//16ms, 50.00%
//排序:升序排序
//模拟, 从后到前排序, 两次两次翻转

class Solution {
public:
	vector<int> pancakeSort(vector<int>& A) {
		int loc = A.size() - 1;

		vector<int> res;
		while (loc < A.size())
		{
			int maxloc = -1;
			int maxval = INT_MIN;
			for (int i = loc; i >= 0; --i)
			{
				if (A[i] > maxval)
				{
					maxval = A[i];
					maxloc = i;
				}
			}
			if (maxloc == loc) loc--;
			else
			{
				//先翻转[0,maxloc]再翻转[0,loc]
				for (int i = 0; i <= maxloc / 2; ++i)
				{
					swap(A[i], A[maxloc - i]);
				}
				res.push_back(maxloc + 1);
				for (int i = 0; i <= loc / 2; ++i)
				{
					swap(A[i], A[loc - i]);
				}
				res.push_back(loc + 1);
				loc--;
			}
		}

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = {3,2,4,1};
	auto res = s->pancakeSort(A);
	return 0;
}
*/
