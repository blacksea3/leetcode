#include "public.h"

//148ms, 92.95%

//��nums�������ԣ�������һ����,���Ҷ����µ������ж��ֲ���
//ע���֦�������һ�����Ѿ���0����/��һ�������ظ��ģ�����һ�����ȣ�����ô���Խ�������/��������
//���ֲ���ʱע���֦������Ѿ��ҵ��˺��ʵ���Ԫ�ԣ���������ֺͺ����������ظ�������������
//  ע�⣺����Ҫ�Ƚϵ�ǰleft��left+1/right��right-1���ɣ�������Ϊ�ҵ��˺��ʵ���Ԫ��һ���Ǵ���ϵ��׸���Ԫ�ԣ���֮ǰ��ͬ
//  �����������֦���裬���������Ԫ�������ͬ

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> returnv = {};
		std::sort(nums.begin(), nums.end());
		int size = nums.size();
		for (int i = 0; i < size - 2; i++)
		{
			if (nums[i] > 0) break;
			if (i&&(nums[i] == nums[i-1])) continue;  //ע�⣺��Ӧ����֮ǰ��i�Ƚϣ�����֦�ظ����
			int target = -1 * nums[i];
			int left = i + 1;
			int right = size - 1;
			while (left < right)
			{
				if ((nums[left] + nums[right]) < target) left++;
				else if ((nums[left] + nums[right]) > target) right--;
				else
				{
					vector<int> temp = { nums[i], nums[left], nums[right] };
					returnv.push_back(temp);
					while ((left < right) && (nums[left] == nums[left + 1])) left++;
					while ((left < right) && (nums[right] == nums[right - 1])) right--;
					left++; 
					right--;
				}
			}
		}
		return returnv;
	}
};
