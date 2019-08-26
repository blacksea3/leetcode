#include "public.h"

//168ms, 81.01%
//simple solution

class Solution {
public:
	vector<int> addToArrayForm(vector<int>& A, int K) {
		int loc = A.size() - 1;
		int carry = 0;
		vector<int> res;
		while (loc >= 0 || K > 0)
		{
			int pA;
			if (loc >= 0) pA = A[loc];
			else pA = 0;
			if (carry)
			{
				res.push_back((K % 10 + pA + 1) % 10);
				carry = (K % 10 + pA + 1) / 10;
				loc--;
				K /= 10;
			}
			else
			{
				res.push_back((K % 10 + pA) % 10);
				carry = (K % 10 + pA) / 10;
				loc--;
				K /= 10;
			}
		}
		if (carry) res.push_back(1);
		reverse(res.begin(), res.end());
		return (res.empty()) ? vector<int>{0} : res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> X = { 0 };
	auto res = s->addToArrayForm(X, 0);
	return 0;
}
*/
