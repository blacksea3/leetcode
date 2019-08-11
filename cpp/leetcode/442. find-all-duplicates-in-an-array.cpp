#include "public.h"

//216ms, 29.06%
//��������, ���������nums[i]��i+1, �����򽻻�, �������λ���Ѿ�������ôres push_back

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
