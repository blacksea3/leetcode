#include "public.h"

//4ms, 83.43%
//simple solution

class Solution {
public:
	int bitwiseComplement(int N) {
		vector<int> nums;

		while (N > 0)
		{
			nums.insert(nums.begin(), N % 2);
			N /= 2;
		}

		if (nums.empty()) return 1;
		else
		{
			for (int i = 0; i < nums.size(); ++i)
			{
				if (nums[i]) nums[i] = 0;
				else nums[i] = 1;
			}
			int res = 0;
			for (int i = 0; i < nums.size(); ++i)
			{
				res = res * 2 + nums[i];
			}
			return res;
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->bitwiseComplement(0) << endl;
	cout << s->bitwiseComplement(5) << endl;
	cout << s->bitwiseComplement(10) << endl;
	return 0;
}
*/