#include "public.h"

//4ms, 70.80%
//从低位往高位寻找第一个高位n<临近低位的元素, 然后将值>高位n的低位中的最小值找出并与其对调,
//接下来对低位们从高位至低位降序排序

class Solution {
public:
	int nextGreaterElement(int n) {
		vector<int> vals;

		while (n > 0)
		{
			vals.insert(vals.begin(), n % 10);
			n /= 10;
		}

		//寻找
		bool isFind = false;
		int index;
		for (index = (int)vals.size() - 2; index >= 0; --index)
		{
			if (vals[index] < vals[index + 1])
			{
				isFind = true;
				break;
			}
		}

		if (!isFind) return -1;
		else
		{
			//index: 这样的一个高位: 值比临近的低位小
			int swapIndex = -1;
			int minVal = INT_MAX;
			for (int iterIndex = index + 1; iterIndex < vals.size(); ++iterIndex)
			{
				if (vals[iterIndex] > vals[index] && vals[iterIndex] < minVal)
				{
					swapIndex = iterIndex;
					minVal = vals[iterIndex];
				}
			}
			//交换位置
			swap(vals[swapIndex], vals[index]);
			//排序
			sort(vals.begin() + index + 1, vals.end(), less<int>());
			//生成结果
			long long res = 0;

			for (int iterIndex = 0; iterIndex < vals.size(); ++iterIndex)
			{
				res *= 10;
				res += vals[iterIndex];
			}
			return (res <= INT_MAX) ? (int)res : -1;
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	auto res = s->nextGreaterElement(12);
	return 0;
}
*/
