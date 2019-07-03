#include "public.h"

//64ms, 30.30%
//O(n^2)DP solution
//考虑到: 如果b>a, b%a == 0, c>b, c%b == 0, 那么 c%a==0

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		sort(nums.begin(), nums.end(), less<int>());

		vector<vector<int>> dp(nums.size(), vector<int>{});
		vector<int> ress;
		int ressize = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			int oldsize = 0;
			vector<int> olds;
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] % nums[j] == 0)
				{
					if (dp[j].size() > oldsize)
					{
						oldsize = dp[j].size();
						olds = dp[j];
					}
				}
			}
			dp[i] = olds;
			dp[i].push_back(nums[i]);
			if (dp[i].size() > ressize)
			{
				ressize = dp[i].size();
				ress = dp[i];
			}
		}
		return ress;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 1,2,3 };
	vector<int> res = s->largestDivisibleSubset(nums);
	return 0;
}
*/

