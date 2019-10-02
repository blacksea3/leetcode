#include "public.h"

//0ms, 100%
//��������˼·:�������ֲ���
//��left < rightʱ
//ÿ����mid, ��nums[mid] > nums[right] ��left = mid + 1
//��nums[mid] < nums[right]��right = mid
//����(nums[mid] == nums[right])ֱ��right--, �������������ҵ�����Сֵ��[left, right-1]��

//���շ���Ψһʣ��Ԫ��left

class Solution {
public:
	int findMin(vector<int>& nums) {
		int le = 0;
		int ri = nums.size() - 1;
		while (le < ri)
		{
			int mid = (le + ri) / 2;
			if (nums[mid] > nums[ri]) le = mid + 1;
			else if (nums[mid] < nums[ri]) ri = mid;
			else ri--;
		}
		return nums[le];
	}
};
