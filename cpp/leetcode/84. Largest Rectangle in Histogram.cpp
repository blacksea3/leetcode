#include "public.h"

//16ms, 81.67%
//
//维护一个单调栈, 内部元素满足: 它们都是下标; 它们对应的高度是越往栈顶, 越高
//如果当前的高度>=栈顶, 则push; 否则对于栈中所有元素, 一边弹出一边计算, 以弹出元素高度为高, 弹出元素索引与原栈顶的内部一个值位置的差-1为宽计算
//当当前元素大于等于栈顶时不用弹出了

//注意: 栈空时单独计算一次, 这次计算的宽相当于从索引为-1连接到原栈顶索引
//循环结束再处理一次栈, 这用heights刚开始末尾加0模拟

class Solution {
public:
	int largestRectangleArea(vector<int>& heights)
	{
		heights.emplace_back(0);
		stack<int> stHeight;  //存储索引
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
