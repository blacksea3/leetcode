#include "public.h"

//44ms, 51.56%
//半DP问题
//s1: acb acb acb..
//s2: a b a b ...
//
//建立两个数组记录: indexr记录每一个s1结束后能匹配到的s2下标, countr记录每一个s2结束后匹配的完整s2个数
//如果某次s2下标已经被记录过了, 说明将要出现循环: 最终s2总数=prev_count+pattern_count+remain_count
//  s2总数见代码

class Solution {
public:
	int getMaxRepetitions(string s1, int n1, string s2, int n2)
	{
		if (n1 == 0) return 0;
		vector<int> indexr(n1); // index at start of each s1 block
		vector<int> countr(n1); // count of repititions till the present s1 block
		int index = 0, count = 0;
		for (int i = 0; i < n1; i++)
		{
			for (int j = 0; j < s1.size(); j++)
			{
				if (s1[j] == s2[index])
					++index;
				if (index == s2.size())
				{
					index = 0;
					++count;
				}
			}
			countr[i] = count;
			indexr[i] = index;
			for (int k = 0; k < i; k++)
			{
				if (indexr[k] == index)
				{
					int prev_count = countr[k];
					int pattern_count = (countr[i] - countr[k]) * ((n1 - 1 - k) / (i - k));
					int remain_count = countr[k + (n1 - 1 - k) % (i - k)] - countr[k];
					return (prev_count + pattern_count + remain_count) / n2;
				}
			}
		}
		return countr[n1 - 1] / n2;
	}
};
