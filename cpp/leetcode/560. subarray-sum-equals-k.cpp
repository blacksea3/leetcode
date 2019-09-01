#include "public.h"

//60ms, 74.92%
//��ǰ0���, ͳ�Ƹ��ֺ͵ĸ���, Ȼ��һ��ɨ��
//�����ǰǰn�����i, ��ôres += i-k�ĸ���

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> countSum;

		int preSum = 0;
		countSum[0]++;
		int res = 0;
		for (auto& num : nums)
		{
			preSum += num;
			if (countSum.find(preSum - k) != countSum.end())
				res += countSum[preSum - k];
			countSum[preSum]++;
		}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> nums = { -1,-1,1 };
	cout << s->subarraySum(nums, 1);
	return 0;
}
