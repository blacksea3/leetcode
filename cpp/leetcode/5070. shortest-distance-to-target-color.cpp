#include "public.h"

//
//先三轮扫描得出各个位置结果, 然后求解

class Solution {
public:
	vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
		int colorSize = colors.size();

		vector<int> colorOne(colorSize, -1);
		vector<int> colorTwo(colorSize, -1);
		vector<int> colorThree(colorSize, -1);

		//三轮扫描开始
		int leftIndex = INT_MIN;
		for (int index = 0; index < colors.size(); ++index)
		{
			if (colors[index] == 1)
			{
				if (leftIndex == INT_MIN)
				{
					for (int tempIndex = 0; tempIndex <= index; ++tempIndex)
					{
						colorOne[tempIndex] = index - tempIndex;
					}
					leftIndex = index;
				}
				else
				{
					for (int tempIndex = leftIndex + 1; tempIndex <= index; ++tempIndex)
					{
						colorOne[tempIndex] = min(tempIndex - leftIndex, index - tempIndex);
					}
					leftIndex = index;
				}
			}
		}
		if (leftIndex != INT_MIN)
		{
			for (int tempIndex = leftIndex + 1; tempIndex < colorSize; ++tempIndex)
			{
				colorOne[tempIndex] = tempIndex - leftIndex;
			}
		}

		leftIndex = INT_MIN;
		for (int index = 0; index < colors.size(); ++index)
		{
			if (colors[index] == 2)
			{
				if (leftIndex == INT_MIN)
				{
					for (int tempIndex = 0; tempIndex <= index; ++tempIndex)
					{
						colorTwo[tempIndex] = index - tempIndex;
					}
					leftIndex = index;
				}
				else
				{
					for (int tempIndex = leftIndex + 1; tempIndex <= index; ++tempIndex)
					{
						colorTwo[tempIndex] = min(tempIndex - leftIndex, index - tempIndex);
					}
					leftIndex = index;
				}
			}
		}
		if (leftIndex != INT_MIN)
		{
			for (int tempIndex = leftIndex + 1; tempIndex < colorSize; ++tempIndex)
			{
				colorTwo[tempIndex] = tempIndex - leftIndex;
			}
		}

		leftIndex = INT_MIN;
		for (int index = 0; index < colors.size(); ++index)
		{
			if (colors[index] == 3)
			{
				if (leftIndex == INT_MIN)
				{
					for (int tempIndex = 0; tempIndex <= index; ++tempIndex)
					{
						colorThree[tempIndex] = index - tempIndex;
					}
					leftIndex = index;
				}
				else
				{
					for (int tempIndex = leftIndex + 1; tempIndex <= index; ++tempIndex)
					{
						colorThree[tempIndex] = min(tempIndex - leftIndex, index - tempIndex);
					}
					leftIndex = index;
				}
			}
		}
		if (leftIndex != INT_MIN)
		{
			for (int tempIndex = leftIndex + 1; tempIndex < colorSize; ++tempIndex)
			{
				colorThree[tempIndex] = tempIndex - leftIndex;
			}
		}

		vector<int> res(queries.size());

		for (int qIndex = 0; qIndex < queries.size(); ++qIndex)
		{
			if (queries[qIndex][1] == 1)
			{
				res[qIndex] = colorOne[queries[qIndex][0]];
			}
			else if (queries[qIndex][1] == 2)
			{
				res[qIndex] = colorTwo[queries[qIndex][0]];
			}
			else
			{
				res[qIndex] = colorThree[queries[qIndex][0]];
			}
		}

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> colors = { 1,1,2,1,3,2,2,3,3 };
	vector<vector<int>> queries = { {1,3},{2,2},{6,1} };
	auto res = s->shortestDistanceColor(colors, queries);
	return 0;
}
*/
