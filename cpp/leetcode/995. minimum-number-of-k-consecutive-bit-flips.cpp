#include "public.h"

//180ms, 29.31%
//大模拟
//直接从最左边的0开始翻
//如果到最后了, 有不足K个0没有翻, 那完蛋了 :)

//模拟的时候放一个队列: 表示修改到哪里了, 如果里面有n个元素, 表示修改了n次, 通过奇偶性判断当前是不是1

class Solution {
public:
	int minKBitFlips(vector<int>& A, int K) {
		int loc = 0;
		int res = 0;
		queue<int> q;
		while (loc <= A.size() - 1)
		{
			while (!q.empty() && q.front() < loc) q.pop();

			if ((A[loc] + q.size()) % 2 == 0)
			{
				if (loc > A.size() - K) return -1;
				q.push(loc + K - 1);
				res++;
			}
			loc++;
		}

		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<int> A = { 1,1,0 };
	auto res = s->minKBitFlips(A, 2);
	return 0;
}
*/
