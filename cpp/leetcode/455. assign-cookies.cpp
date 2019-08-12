#include "public.h"

//60ms, 44.41%
//贪婪
//给胃口排序
//给饼干排序
//最小的饼干能给胃口最小的孩子, 那就给; 否则看下一个饼干
//直到没有孩子或者饼干结束

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		int gloc = 0;
		int sloc = 0;
		int res = 0;
		while (gloc < g.size() && sloc < s.size())
		{
			if (g[gloc] <= s[sloc])
			{
				res++;
				gloc++;
				sloc++;
			}
			else
			{
				sloc++;
			}
		}
		return res;
	}
};
