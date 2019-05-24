#include "public.h"

//12ms, 82.85%

//KMP algorithm

//I will skip this algorithm now, this is difficult :(

class Solution {
public:
	int strStr(string haystack, string needle) {
		//使用KMP算法
		if (needle == "") return 0;
		if (haystack.size() < needle.size()) return -1;

		int i = 0;
		int j = 0;
		int jmax = needle.size() - 1;
		while (true)
		{
			if (i == haystack.size()) break;
			if (haystack[i] == needle[j])
			{
				if (j == jmax) return i - jmax;
				else
				{
					j++;
					i++;
				}
			}
			else
			{
				int resj = strStr_next(needle, j);
				if (resj == -1)
				{
					j = 0;
					i++;
				}
				else j = resj;
			}
		}

		return -1;
	}

	//得到下一个指针位置,详情见KMP算法,
	//外部必须确保0<=j<needle.size() 
	int strStr_next(string needle, int j)
	{
		vector<int> next(j + 1);
		next[0] = -1;
		int k = -1;
		int iterloc = 0;

		while (iterloc < j)
		{
			if ((k == -1) || (needle[k] == needle[iterloc]))
			{
				iterloc++;
				k++;
				next[iterloc] = k;
			}
			else k = next[k];
		}
		return next[j];
	}
};
