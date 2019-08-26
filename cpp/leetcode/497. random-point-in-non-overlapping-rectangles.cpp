#include "public.h"

//180ms, 51.72%
//���ص��ľ���, �������������Ȩ��ѡ��
//���ʹ��upRow - downRow + 1, ��ͬ��, ע��������, Ҫ��һ

class Solution {
private:
	vector<int> recSizes;  //�±��Ӧ�����������䵽�����λ��, ע��: recSizes����ÿ��ֵ��һ�����"��"
	//���忴����ʵ��
	//����:�������Ϊ4��9 {4, 13}; 
	//�������:0, 1, 2, 3 < index(0); 4,5,6,7,8,9,10,11,12 < index(1)
	//���ֲ��ҵ�һ�����������������, ��Ϊ��Ӧ�ľ���
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
