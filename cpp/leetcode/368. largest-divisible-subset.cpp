#include "public.h"

//36ms, 90.35%
//O(n^2) DP solution
//考虑到: 如果b>a, b%a == 0, c>b, c%b == 0, 那么 c%a==0
//dp[i]存放: 比nums[i]小的最长的整除子集大小(包括自己)
//再放一个dp2[i]表示i的前驱元素在nums中的下标

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		int nSize = nums.size();
		sort(nums.begin(), nums.end(), less<int>());

		vector<int> dp(nSize, 1);
		vector<int> dp2(nSize, -1);
		int resLen = 0;
		int resIndex = -1;

		for (int i = 0; i < nSize; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] % nums[j] == 0)
				{
					if (dp[j] >= dp[i])
					{
						dp[i] = dp[j] + 1;
						dp2[i] = j;
					}
				}
			}
			if (dp[i] > resLen)
			{
				resLen = dp[i];
				resIndex = i;
			}
		}

		vector<int> vres;
		while (resIndex != -1)
		{
			vres.emplace_back(nums[resIndex]);
			resIndex = dp2[resIndex];
		}
		reverse(vres.begin(), vres.end());
		return vres;
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

