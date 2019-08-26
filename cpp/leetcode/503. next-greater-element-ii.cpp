#include "public.h"

//220ms, 29.53%
//一遍搜索
//栈, 记录最大值
//类似最小栈

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		if (nums.empty()) return {};
		int maxVal = *max_element(nums.begin(), nums.end());
		stack<pair<int, int>> st; //val, index
		vector<int> res(nums.size(), INT_MIN);

		int index = 0;
		int num_caled = 0;

		while (num_caled < nums.size())
		{
			while (!st.empty() && st.top().first < nums[index])
			{
				pair<int, int> temp = st.top();
				if (res[temp.second] == INT_MIN)
				{
					res[temp.second] = nums[index];
					num_caled++;
				}
				st.pop();
			}
			if (nums[index] == maxVal)
			{
				if (res[index] == INT_MIN)
				{
					res[index] = -1;
					num_caled++;
				}
			}
			else
			{
				st.push(pair<int, int>{nums[index], index});
			}
			index++;
			if (index == nums.size())
			{
				index = 0;
			}
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 1,2,3,2,1 };
	auto res = s->nextGreaterElements(nums);
	return 0;
}
*/
