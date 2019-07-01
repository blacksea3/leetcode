#include "public.h"

//16ms, 83.13%
//��Ч������: �±�->ֵ
//һ�����ڻ�, �ҳ���ʼ����

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int fast = nums[nums[0]];
		int slow = nums[0];

		while (fast != slow)
		{
			fast = nums[nums[fast]];
			slow = nums[slow];
		}

		//��ͷ��ʼ
		slow = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}

		return fast;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = { 1,3,4,2,2 };
	cout << s->findDuplicate(nums);
	return 0;
}
*/
