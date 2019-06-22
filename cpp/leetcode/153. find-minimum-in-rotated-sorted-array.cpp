#include "public.h"

//���ֲ���,ע�����������ظ�Ԫ��,8ms, 83.60%

class Solution {
private:
	//ȷ�����벻Ϊ��nums, start��end�����±�
	int iter_findMin(vector<int>& nums, int start, int end)
	{
		//���ֲ���
		if (nums[start] <= nums[end]) //����ϲ�����numֻ��һ��Ԫ�ص�����
			return nums[start];
		else
		{
			int mid = (start + end) / 2;  //��num����>=2ʱ,����±�start��min �� min+1��end�����ж�
			if (nums[start] <= nums[mid])
				return iter_findMin(nums, mid + 1, end);
			else
				return iter_findMin(nums, start, mid);
		}
	}

public:
	int findMin(vector<int>& nums) {
		//��������Ŀ���������������
		return iter_findMin(nums, 0, nums.size() - 1);
	}
};