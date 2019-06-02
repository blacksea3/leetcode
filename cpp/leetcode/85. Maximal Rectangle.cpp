#include "public.h"

//24ms, 97.79%

//You can reuse the code from problem 84,
//for each line, the upper lines contains continuous '1' can be the height of each column
//Then caculate the max size of each matrix is ok

class Solution {
private:
	int largestRectangleArea(const vector<int>& heights)
	{
		//use Monotonic stack(µ¥µ÷Õ»)
		//from https://blog.csdn.net/lv1224/article/details/79974175

		vector<int> stack = {};
		int hsize = heights.size();
		int maxArea = 0;
		if (hsize == 0) return 0;

		for (int i = 0; i < hsize; i++)
		{
			if (stack.empty() || heights[stack[stack.size() - 1]] <= heights[i]) stack.push_back(i);
			else
			{
				while (!stack.empty() && heights[stack[stack.size() - 1]] > heights[i])
				{
					int top = stack[stack.size() - 1];
					stack.pop_back();
					if (stack.empty()) maxArea = max(heights[top] * i, maxArea);
					else maxArea = max(heights[top] * (i - stack[stack.size() - 1] - 1), maxArea);
				}
				stack.push_back(i);
			}
		}

		while (!stack.empty())
		{
			int top = stack[stack.size() - 1];
			stack.pop_back();
			if (stack.empty()) maxArea = max(heights[top] * (hsize), maxArea);
			else maxArea = max(heights[top] * (hsize - stack[stack.size() - 1] - 1), maxArea);
		}
		return maxArea;
	}
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		//m rows, n columns
		int m = matrix.size();
		if (m == 0) return 0;
		int n = matrix[0].size();
		if (n == 0) return 0;

		vector<vector<int>> heights(m, vector<int>(n, 0));

		for (int j = 0; j < n; j++)
			heights[0][j] = (matrix[0][j] == '1') ? 1 : 0;

		for (int i = 1; i < m; i++)
			for (int j = 0; j < n; j++)
				heights[i][j] = (matrix[i][j] == '1') ? heights[i - 1][j] + 1 : 0;

		int maxsize = 0;

		for (int i = 0; i < m; i++)
			maxsize = max(maxsize, largestRectangleArea(heights[i]));

		return maxsize;
	}
};