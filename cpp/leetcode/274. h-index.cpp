#include "public.h"

/*
//12ms, 37.73%
//simple solution
//排序

class Solution {
public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end(), greater<int>());

		int i = 0;

		while ((i < citations.size()) && (citations[i] > i)) i++;
		return i;
	}
};
*/

//8ms, 82.85%
//计数法, 首先将引用超过论文总数的论文引用设置成论文数量
//然后数每个引用次数, 记录在一个vector里面

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int n = citations.size();
		vector<int> papers(n + 1,0);
		// 计数
		for (auto& c : citations)
			papers[min(n, c)]++;
		// 找出最大的 k
		int k = n;
		for (int s = papers[n]; k > s; s += papers[k])
			k--;
		return k;
	}
};
