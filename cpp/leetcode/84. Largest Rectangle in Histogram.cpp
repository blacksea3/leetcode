#include "public.h"

//16ms, 81.67%
//
//ά��һ������ջ, �ڲ�Ԫ������: ���Ƕ����±�; ���Ƕ�Ӧ�ĸ߶���Խ��ջ��, Խ��
//�����ǰ�ĸ߶�>=ջ��, ��push; �������ջ������Ԫ��, һ�ߵ���һ�߼���, �Ե���Ԫ�ظ߶�Ϊ��, ����Ԫ��������ԭջ�����ڲ�һ��ֵλ�õĲ�-1Ϊ�����
//����ǰԪ�ش��ڵ���ջ��ʱ���õ�����

//ע��: ջ��ʱ��������һ��, ��μ���Ŀ��൱�ڴ�����Ϊ-1���ӵ�ԭջ������
//ѭ�������ٴ���һ��ջ, ����heights�տ�ʼĩβ��0ģ��

class Solution {
public:
	int largestRectangleArea(vector<int>& heights)
	{
		heights.emplace_back(0);
		stack<int> stHeight;  //�洢����
		int maxSize = 0;

		int index;
		for (index = 0; index < heights.size(); ++index)
		{
			while (!stHeight.empty() && heights[stHeight.top()] > heights[index]) {
				int preHeight = heights[stHeight.top()];
				stHeight.pop();
				maxSize = max(maxSize, preHeight*(stHeight.empty() ? index : (index - stHeight.top() - 1)));
			}
			stHeight.push(index);
		}
		return maxSize;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> heights = {2,1,2};
	auto res = s->largestRectangleArea(heights);
	return 0;
}
*/
