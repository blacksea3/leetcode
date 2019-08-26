#include "public.h"

//
//放置一个unordered_map<int, int> um: 键高度, 值loc
//放置一个deque<int> 高度们, 
//upper_bound 寻找高度们大于查找值的第一个位置, 那么maxbias = max(maxbias, 此位置-查找位置-1), 但是若查找位置是begin第一个, 那么新增这个高度与位置

class Solution {
public:
	int maxWidthRamp(vector<int>& A) {
		unordered_map<int, int> um;
		deque<int> heights;

		int res = 0;
		um[A[0]] = 0;
		heights.push_back(A[0]);

		for (int i = 1; i < A.size(); ++i)
		{
			deque<int>::iterator iter = upper_bound(heights.begin(), heights.end(), A[i]);
			if (iter == heights.begin())
			{
				um[A[i]] = i;
				heights.push_front(A[i]);
			}
			else
			{
				res = max(res, i - um[*(iter - 1)]);
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = { 6,0,8,2,1,5 };
	auto res = s->maxWidthRamp(A);
	return 0;
}
*/
