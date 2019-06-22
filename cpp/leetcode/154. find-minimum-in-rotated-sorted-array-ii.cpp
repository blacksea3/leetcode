#include "public.h"

//����153��ֻ�����������ظ�Ԫ��, 12ms 78.06%

class Solution {
public:
	int iter_findMin(vector<int>& nums, int start, int end)
	{
		//���ֲ���
		if (start == end)  //һ��Ԫ��
			return nums[start];
		else
		{
			if (nums[start] < nums[end])
			{
				return nums[start];
			}
			else if (nums[start] > nums[end])
			{
				int mid = (start + end) / 2;  //��num����>=2ʱ,����±�start��min �� min+1��end�����ж�
				if (nums[start] <= nums[mid])   //���� 2 2 2 3 1����  2 2 2 0 1����Ҫ��,�ϲ���ȥ
					return iter_findMin(nums, mid + 1, end);
				else
					return iter_findMin(nums, start, mid);
			}
			else   //Ҫ�����2 3 0 1 2���� 2 2 2 2 2 ���� 2 3 4 1 2
			{
				//�򵥵�,O(n)������
				for (int i = start; i <= end; i++)
				{
					if (nums[i] < nums[start])
						return nums[i];
					else if (nums[i] > nums[start])
					{
						return iter_findMin(nums, i, end);
					}
					else;
				}
				return nums[start];
			}
		}
	}


public:
	int findMin(vector<int>& nums) {
		return iter_findMin(nums, 0, nums.size() - 1);
	}
};
