#include "public.h"

//12ms, 96.55%
//����, Ȼ��Ϳ�����

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), greater<int>());
		return nums[k - 1];
	}
};

