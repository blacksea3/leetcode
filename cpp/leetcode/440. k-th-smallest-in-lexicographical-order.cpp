#include "public.h"

//0ms, 100%
//十叉树, int数的高位为根, 低位为儿子

class Solution {
private:
	int n;

	//参数: prefix: 树前缀: 即从根部到当前节点(当前根节点)的值
	//返回以当前根节点为根的十叉树的节点总数
	//一般情况下此总数将是1/11/111...等
	int getNumOfNodes(int prefix)
	{
		int count = 0;
		for (long long cur = prefix, next = prefix + 1; cur <= this->n; cur *= 10, next *= 10)
			count += min(next, (long long)this->n + 1) - cur;
		return count;
	}

public:
	int findKthNumber(int n, int k) {
		this->n = n;
		int p = 1;
		int prefix = 1;
		while (p < k)
		{
			int count = getNumOfNodes(prefix);
			if ((p + count) > k)   //字典序第k的数在当前前缀下
			{
				prefix *= 10;
				p++;
			}
			else //字典序第k的数不在当前前缀下, 那应该增加当前前缀
			{
				prefix++;
				p += count;
			}
		}
		return prefix;
	}
};
