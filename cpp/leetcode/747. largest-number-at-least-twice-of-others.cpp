#include "public.h"

//4ms, 87.73%
//找到最大和次大元素
//若有不止一个最大元素, 则返回-1, 此时索引尽管记录的是最后一个元素, 但是不影响结果

class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		int maxMax = INT_MIN;
		int maxSecond = INT_MIN;
		int maxMaxIndex = -1;

		for (int index = 0; index < nums.size(); ++index)
		{
			int num = nums[index];
			if (num >= maxMax)
			{
				maxSecond = maxMax;
				maxMax = num;
				maxMaxIndex = index;
			}
			else
			{
				if (num > maxSecond)
				{
					maxSecond = num;
				}
			}
		}

		return ((maxSecond == INT_MIN) || (maxMax >= 2 * maxSecond)) ? maxMaxIndex : -1;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 0,0,0,1 };
	auto res = s->dominantIndex(nums);
	return 0;
}