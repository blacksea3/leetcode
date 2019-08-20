#include "public.h"

//36ms, 40.55%
//半暴力: 直接将A扩展:至长度刚好>=B, 用这个字符串以及再扩展一个A的字符串 和 B比较, 判断结果

class Solution {
public:
	int repeatedStringMatch(string A, string B) {
		int aSize = A.size();
		int bSize = B.size();
		int res = 1;
		int expand_aSize = aSize;

		string expandA = A;
		while (expand_aSize < bSize)
		{
			expand_aSize += aSize;
			expandA.append(A);
			res++;
		}

		if (expandA.find(B) != expandA.npos) return res;
		else
		{
			expandA.append(A);
			res++;
			if (expandA.find(B) != expandA.npos) return res;
			else return -1;
		}
	}
};
