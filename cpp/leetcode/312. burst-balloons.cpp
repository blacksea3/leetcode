#include "public.h"

//20ms, 98.42%
//DP problem
//将nums两端扩展: 例如3 1 5 8 扩展为 1 3 1 5 8 1
//定义dp[i][j]表示戳破下标:[i,j]后的最大收益
//按长度更新dp, 首先初始化长度为1, 即i==j得,然后
//    当求dp[i][j]时 其=  max( nums[i]*nums[i-1]*nums[j+1] + dp[i+1][j], nums[j]*nums[i-1]*nums[j+1] + dp[i][j-1],
//        nums[k]*nums[i-1]*nums[j+1] + dp[i][k-1] + dp[k+1][j] when i+1<=k<=j-1)

class Solution {
public:
	int maxCoins(vector<int>& nums) {
		vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2));
		nums.push_back(1);
		nums.insert(nums.begin(), 1);

		//init
		for (int i = 1; i < nums.size() - 1; ++i)
			dp[i][i] = nums[i - 1] * nums[i] * nums[i + 1];

		//cal
		for (int len = 2; len < nums.size() - 1; ++len)
		{
			for (int i = 1; i < nums.size() - len; ++i)
			{
				int j = i + len - 1;
				int tempmul = nums[i - 1] * nums[j + 1];
				int tempmax = max(nums[i] * tempmul + dp[i + 1][j], nums[j] * tempmul + dp[i][j - 1]);
				for (int k = i + 1; k <= j - 1; ++k)
					tempmax = max(tempmax, nums[k] * tempmul + dp[i][k - 1] + dp[k + 1][j]);
				dp[i][j] = tempmax;
			}
		}

		return dp[1][nums.size() - 2];
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 3,1,5,8 };
	cout << s->maxCoins(nums);
	return 0;
}
*/