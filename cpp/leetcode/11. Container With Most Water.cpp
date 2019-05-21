#include "public.h"

//16ms 99.73%

//考虑这样的方法,给定两个指针,一个从左边起,一个从右边起,两个指针一开始指向height的边界值
//每次移动左右两个指针之一,一格位置
//  每次移动指向较低的值的指针,如果这个指针指向了一个更大的数,那么
//  计算新的两个指针指向的位置构成的容器容纳的水的量,并与历史值比较,若高则记录

//直至两个指针距离为1

class Solution {
public:
	int maxArea(vector<int>& height) {
		//init, 默认数字均>=0,至少有两个元素
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
