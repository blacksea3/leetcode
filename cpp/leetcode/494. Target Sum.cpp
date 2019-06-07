#include "public.h"

//BRUTE FORCE is O(2^n), will TLE!

//so we use DP, 32ms, 67.54% :(
//note that: for all the pre sums, if we push into one number(c), then if we can have m way to get one old sum(n),
//  for the new sum n-c and n+c, we can have m way to get them!

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		auto sum = accumulate(nums.cbegin(), nums.cend(), 0); // 可以获得的和从-sum到sum
		if (S > sum || S < -sum) return 0;
		int vsumsize = 2 * sum + 1;

		vector<int> vsum(vsumsize, 0);
		vsum[sum] = 1;  //init
		

		for (size_t i = 0; i < nums.size(); ++i)
		{
			vector<int> newsum(vsumsize, 0);
			for (size_t j = 0; j < vsumsize; ++j) { // 对每个s更新c
				if (vsum[j]) {
					newsum[j + nums[i]] += vsum[j];
					newsum[j - nums[i]] += vsum[j];
				}
			}
			vsum.assign(newsum.begin(), newsum.end());
		}


		return vsum[sum+S];
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 1,1,1,1,1 };
	cout << s->findTargetSumWays(nums, 3);
	return 0;
}

