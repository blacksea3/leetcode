#include "public.h"

//108ms, 77.78%
//�ҿ�������, ������������Ȼ���������

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		vector<int> cpnums = nums;
		sort(cpnums.begin(), cpnums.end());
		int loc = 0;

		for (int i = (nums.size() - 1)/2*2; i >= 0; i -= 2)
			nums[i] = cpnums[loc++];

		for (int i = nums.size() / 2 * 2 - 1; i >= 1; i -= 2)
			nums[i] = cpnums[loc++];
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<int> nums = { 1,3,2,2,3,1 };
	vector<int> nums = { 4,5,5,6 };
	s->wiggleSort(nums);
	return 0;
}
*/
