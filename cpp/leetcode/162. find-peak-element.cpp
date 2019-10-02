#include "public.h"

//���ֲ���, 4ms, 97.09%
//���nums[mid] < nums[mid+1]��mid+1��end���ַ�ֵԪ�� left = mid + 1
//����start��midһ����Ԫ��
//ע�����ڵ�Ԫ�ز�ͬ

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left < right)
		{
			mid = (right + left) / 2;
			if (nums[mid] < nums[mid + 1])
				left = mid + 1;
			else
				right = mid;
		}

		return left;

	}
};
