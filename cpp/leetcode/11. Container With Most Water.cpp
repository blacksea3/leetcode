#include "public.h"

//16ms 99.73%

//���������ķ���,��������ָ��,һ���������,һ�����ұ���,����ָ��һ��ʼָ��height�ı߽�ֵ
//ÿ���ƶ���������ָ��֮һ,һ��λ��
//  ÿ���ƶ�ָ��ϵ͵�ֵ��ָ��,������ָ��ָ����һ���������,��ô
//  �����µ�����ָ��ָ���λ�ù��ɵ��������ɵ�ˮ����,������ʷֵ�Ƚ�,�������¼

//ֱ������ָ�����Ϊ1

class Solution {
public:
	int maxArea(vector<int>& height) {
		//init, Ĭ�����־�>=0,����������Ԫ��
		bool isLeftHigher;
		int left = 0;
		int right = height.size() - 1;
		int maxarea = (height.size() - 1) * min(height[0], height[right]);

		while (left < right)
		{
			if (height[right] < height[left])
			{
				right--;
				maxarea = max(maxarea, min(height[right], height[left])*(right - left));
			}
			else
			{
				left++;
				maxarea = max(maxarea, min(height[right], height[left])*(right - left));
			}
		}
		return maxarea;
	}
};
