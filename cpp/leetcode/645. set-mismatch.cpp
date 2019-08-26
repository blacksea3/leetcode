#include "public.h"

//40ms, 86.95%
//���±������: nums[index]��index + 1,
//�ٱ���һ�������ҵ����ݲ���Ӧ��λ��, ��Ӧȱʧ�����ֺ��ظ�������

class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		int numsSize = nums.size();
		int duplicate;
		int notfound;

		for (int index = 0; index < numsSize; ++index)
		{
			while (nums[index] != index + 1 && nums[nums[index] - 1] != nums[index])
			{
				swap(nums[index], nums[nums[index] - 1]);
			}
		}

		for (int index = 0; index < numsSize; ++index)
		{
			if (nums[index] != index + 1)
			{
				notfound = index + 1;
				duplicate = nums[index];
				break;
			}
		}
		return { duplicate, notfound };
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 1,2,2,4 };
	auto res = s->findErrorNums(nums);
	return 0;
}
*/
