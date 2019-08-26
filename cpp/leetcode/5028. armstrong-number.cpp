#include "public.h"

//
//simple solution

class Solution {
public:
	bool isArmstrong(int N) {
		vector<int> v;
		int tempn = N;
		while (N > 0)
		{
			v.push_back(N % 10);
			N /= 10;
		}

		int sum = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			sum += (int)(pow(v[i], v.size()));
		}
		return sum == tempn;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->isArmstrong(153);
	return 0;
}
*/
