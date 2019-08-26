#include "public.h"

//
//交换
//用假设的方法

class Solution {
public:
	int minDominoRotations(vector<int>& A, vector<int>& B) {
		int res = INT_MAX;

		for (int i = 1; i <= 6; ++i)
		{
			int count = 0;
			int same = 0;
			bool can = true;
			for (int j = 0; j < A.size(); ++j)
			{
				if (A[j] == i && B[j] == i) same++;
				else if (A[j] == i) continue;
				else if (B[j] == i) count++;
				else
				{
					can = false;
				}
			}
			if (can)
			{
				res = min(res, min((int)A.size() - same - count, count));
			}
		}
		return (res == INT_MAX) ? -1 : res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = {1, 2, 1, 1, 1, 2,2, 2};
	vector<int>	B = { 2, 1, 2, 2, 2,2,2,2 };
	cout << s->minDominoRotations(A, B);
	return 0;
}
*/
