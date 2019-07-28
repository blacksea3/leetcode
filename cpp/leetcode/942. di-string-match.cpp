#include "public.h"

//56ms, 94.65%
//按规律放置: 先放大的: 从左边往右边数: 遇到一个D放一个最大的, 再遇到一个D放一个次大的..
//然后从右边往左边数:遇到一个I放当前最大的...直到放满

class Solution {
public:
	vector<int> diStringMatch(string S) {
		vector<int> res(S.size() + 1);
		int pre = S.size();

		for (int i = 0; i < S.size(); ++i)
		{
			if (S[i] == 'D') res[i] = pre--;
		}
		res[S.size()] = pre--;
		for (int i = S.size() - 1; i >= 0; --i)
		{
			if (S[i] == 'I') res[i] = pre--;
		}
		return res;
	}
};
