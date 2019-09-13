#include "public.h"

//24ms, 90.21%
//����84��,
//��ÿһ��, �����������1�ĸ�������ÿһ�еĸ߶�, ��ÿһ��Ϊ�ײ���������
//������¼��ǰ�е�ÿ�и߶�, ���и���

class Solution {
private:
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

public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (m == 0) return 0;
		int n = matrix[0].size();
		if (n == 0) return 0;
		
		vector<int> heights(n, 0);
		int maxsize = 0;

		for (int r = 0; r < m; r++)
		{
			for (int c = 0; c < n; c++)
			{
				heights[c] = (matrix[r][c] == '1') ? heights[c] + 1 : 0;
			}
			maxsize = max(maxsize, largestRectangleArea(heights));
		}
		return maxsize;
	}
};
