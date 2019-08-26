#include "public.h"

//216ms, 29.06%
//用索引存, 理想情况下nums[i]存i+1, 不是则交换, 如果交换位置已经是了那么res push_back

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != i + 1 && nums[i] != -1)
			{
				while (nums[i] != i + 1 && nums[i] != -1)
				{
					if (nums[nums[i] - 1] != nums[i])
					{
						swap(nums[nums[i] - 1], nums[i]);
					}
					else
					{
						res.push_back(nums[i]);
						nums[i] = -1;
						break;
					}
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 2, 1 };
	auto res = s->findDuplicates(nums);
	//vector<int> nums = { 4,3,2,7,8,2,3,1 };
	//auto res = s->findDuplicates(nums);
	return 0;
}
