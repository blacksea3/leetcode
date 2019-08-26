#include "public.h"

//4ms, 85.37%
//˫��dp, ����С���: ֻʣ��һ�����ֿ�ʼ
//dp[i][j]��ʾʣ��nums[i]��nums[j]��ʱ��, ��ǰ������ֱ���һλ��Ҷ��������, 
//��󷵻�dp[0][nums.length - 1]�Ƿ����0����

class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int numSize = nums.size();
		vector<vector<int>> dp(numSize, vector<int>(numSize, 0));
		//��ʼ��
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
