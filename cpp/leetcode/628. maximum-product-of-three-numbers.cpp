#include "public.h"

//140ms, 5.39%
//�ҳ��������������Լ���С����������
//���������������֮��������������������С�ĸ���֮��
//��: ֱ������������������С��������, Ȼ��ȽϾ���
//Ϊ�򻯴���, ֱ��sort

class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		return max(nums[0] * nums[1] * nums[nums.size() - 1],
			nums[nums.size() - 3] * nums[nums.size() - 2] * nums[nums.size() - 1]);
	}
};
