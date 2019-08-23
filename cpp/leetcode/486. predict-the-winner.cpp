#include "public.h"

//4ms, 85.37%
//双端dp, 从最小情况: 只剩下一个数字开始
//dp[i][j]表示剩下nums[i]到nums[j]的时候, 当前玩家先手比另一位玩家多的最大分数, 
//最后返回dp[0][nums.length - 1]是否大于0即可

class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int numSize = nums.size();
		vector<vector<int>> dp(numSize, vector<int>(numSize, 0));
		//初始化
		for (int i = 0; i < numSize; i++) {
			dp[i][i] = nums[i];
		}
		//DP
		for (int i = numSize - 1; i >= 0; i--) {
			for (int j = i + 1; j < numSize; j++) {
				dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
			}
		}
		return dp[0][numSize - 1] >= 0;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> nums = {1,5,2};
	cout << s->PredictTheWinner(nums);
	return 0;
}
