#include "public.h"

//44ms, 34.03%
//图
//建立以下连接关系: 对于索引i, i的下一个节点是A[i]
//考虑到这个数组恰好包含0 - N-1, 没有重复元素, 因此可以认为
//图由多个环组成
//那么只需要一轮搜索就可

class Solution {
public:
	int arrayNesting(vector<int>& nums) {
		int nsize = nums.size();
		vector<bool> isSearched(nsize, false);

		int index = 0;
		int res = 0;

		while (index < nsize)
		{
			//开始搜索
			int preLen = 0;
			while (!isSearched[index])
			{
				isSearched[index] = true;
				index = nums[index];
				preLen++;
			}
			res = max(res, preLen);
			//移动搜索起点
			while (index < nsize && isSearched[index]) index++;
		}
		return res;
	}
};
