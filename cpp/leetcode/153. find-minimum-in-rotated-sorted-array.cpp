#include "public.h"

//4ms, 90.72%
//���ֲ���, ���������ظ�Ԫ��

class Solution {
private:
	//ȷ�����벻Ϊ��nums, start��end�����±�
	int mBinarySearch(vector<int> const& nums, int start, int end)
	{
		//���ֲ���
		if (nums[start] <= nums[end]) //numֻ��һ��Ԫ�ػ��ߵ�ǰ������
			return nums[start];
		else
		{
			int mid = (start + end) / 2;  //��num����>=2ʱ,����±�start��min �� min+1��end�����ж�
			if (nums[start] <= nums[mid])
				return mBinarySearch(nums, mid + 1, end);
			else
				return mBinarySearch(nums, start, mid);
		}
	}

public:
	int findMin(vector<int>& nums) {
		//��������Ŀ���������������
		return mBinarySearch(nums, 0, nums.size() - 1);
	}
};
