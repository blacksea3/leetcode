#include "public.h"

//20ms, 88.00%

//HARD problem, speial algorithm, use Monotonic stack(µ¥µ÷Õ»)
//from https://blog.csdn.net/lv1224/article/details/79974175
// I cannot write it by self :(

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
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
};