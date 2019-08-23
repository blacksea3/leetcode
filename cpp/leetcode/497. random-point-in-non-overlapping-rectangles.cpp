#include "public.h"

//180ms, 51.72%
//非重叠的矩阵, 按矩阵面积进行权重选择
//面积使用upRow - downRow + 1, 列同理, 注意整数点, 要加一

class Solution {
private:
	vector<int> recSizes;  //下标对应着这个矩阵分配到的面积位置, 注意: recSizes里面每个值是一个面积"和"
	//具体看代码实现
	//例如:矩阵面积为4和9 {4, 13}; 
	//则随机数:0, 1, 2, 3 < index(0); 4,5,6,7,8,9,10,11,12 < index(1)
	//二分查找第一个大于随机数的索引, 则为对应的矩阵
	vector<vector<int>> memory;

public:
	Solution(vector<vector<int>>& rects) {
		memory = rects;
		int preSum = 0;
		for (auto& rect : rects)
		{
			int rSize = (rect[2] - rect[0] + 1)*(rect[3] - rect[1] + 1);
			preSum += rSize;
			recSizes.push_back(preSum);
		}
	}

	vector<int> pick() {
		int randomMax = recSizes[recSizes.size() - 1];
		int randomVal = rand() % randomMax;
		vector<int>::iterator iter = upper_bound(recSizes.begin(), recSizes.end(), randomVal);
		int absIndex = iter - recSizes.begin();

		int startX = memory[absIndex][0];
		int startY = memory[absIndex][1];
		int deltaX = memory[absIndex][2] - memory[absIndex][0];
		int deltaY = memory[absIndex][3] - memory[absIndex][1];

		int resX = rand() % (deltaX + 1) + startX;
		int resY = rand() % (deltaY + 1) + startY;
		return { resX, resY };
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
