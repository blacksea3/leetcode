#include "public.h"

//���ֲ���, 4ms, 99.16%

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		//��������
		//ע�⵽:   nums[mid] < nums[mid+1]   1 4 3 2 1  �������, �ܻ���mid+1��end���ַ�ֵԪ��
		//������Ϊmid+1��end���������˶���
		//����start��midһ����Ԫ��

		//ע�����ڵ�Ԫ�ز�ͬ

		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left < right)
		{
			mid = left + (right - left) / 2;
			if (nums[mid] < nums[mid + 1])
				left = mid + 1;
			else
				right = mid;
		}

		return left;

	}
};
